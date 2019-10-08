#include "stdlib.h"
#include "string.h"

#include "ht_linear_prob.h"

static ht_item dummyItem = {NULL, NULL};

ht_item* ht_linear_get(ht_table* htable, const char* key) {
  int hash = ht_hash(key);
  int curr = hash % htable->size;
  int start = curr;
  while (htable->items[curr]) {
    ht_item* curr_item = htable->items[curr];
    const char* curr_key = curr_item->key;
    if (strcmp(curr_key, key) == 0) {
      return curr_item;
    }
  }
  return 0;
}

int ht_linear_set(ht_table* htable, ht_item* item) {
  int hash = ht_hash(item->key);
  int curr = hash % htable->size;
  int start = curr;
  while (htable->items[curr]) {
    if(strcmp(htable->items[curr]->key, item->key) == 0) {
      ht_del_item(htable->items[curr]);
      htable->items[curr] = item;
      return 0;
    }
    curr++;
    curr = curr % htable->size; // wrap around
    if (curr == start) { // table is full
      return -1;
    }
  }
  
  htable->items[curr] = item;  
  return 0;
}

int ht_linear_remove(ht_table* htable, const char* key) {
  int hash = ht_hash(key);
  int curr = hash % htable->size;
  while (htable->items[curr]) {
    if (strcmp(htable->items[curr]->key, key)) {
      ht_del_item(htable->items[curr]);
      htable->items[curr] = &dummyItem;
    }

    return 0;
  }
  return -1;
}
