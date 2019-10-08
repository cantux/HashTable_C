#include <stdlib.h>
#include <string.h>

#include "ht.h"
#include "strat/ht_linear_prob.h"
#include "strat/ht_simple_strat.h"
#include "math.h"

#define CAPACITY 0xFFFF
#define ALPHABET_SIZE 128
#define PRIME 151

ht_item* ht_new_item(const char* k, const char* v) {
    ht_item* i = malloc(sizeof(ht_item));
    i->key = strdup(k);
    i->value = strdup(v);
    return i;
}

ht_table* ht_new(int strategy) {
    ht_table* ht = malloc(sizeof(ht_table));
    ht->size = CAPACITY;
    ht->count = 0;
    ht->items = calloc((size_t)ht->size, sizeof(ht_item*));

    switch (strategy) {
      case LINEAR_PROBING:
        ht->get = ht_linear_get;
        ht->set = ht_linear_set;
        ht->remove = ht_linear_remove;
        break;
      case SIMPLE_STRAT:
      defualt:
        ht->get = ht_simple_get;
        ht->set = ht_simple_set;
        ht->remove = ht_simple_remove;
    }
    return ht;
}

void ht_del_item(ht_item* i) {
    free(i->key);
    free(i->value);
    free(i);
}

void ht_del_hash_table(ht_table* ht) {
    for (int i = 0; i < ht->size; i++) {
        ht_item* item = ht->items[i];
        if (item != NULL) {
            ht_del_item(item);
        }
    }
    free(ht->items);
    free(ht);
}

int ht_set(ht_table* h_table, ht_item* item) {
  return h_table->set(h_table, item);
}

ht_item* ht_get(ht_table* h_table, const char* key) {
  return h_table->get(h_table, key);
}

int ht_remove(ht_table* table, const char* key) {
  return table->remove(table, key);
}

int ht_hash(const char* key) {
  long hash = 0;
  for(int i = 0; i < strlen(key); i++) {
    hash += key[i] * pow(PRIME, i);
    hash = hash % CAPACITY;
  }
  return hash;
}
