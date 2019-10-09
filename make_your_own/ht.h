#ifndef HT_H
#define HT_H

#define LINEAR_PROBING 1
#define SIMPLE_STRAT 255

typedef struct ht_item {
    char* key;
    char* value;
} ht_item;

typedef struct ht_table {
    int size;
    int count;
    ht_item** items;
    int (*set)(struct ht_table*, struct ht_item*);
    struct ht_item* (*get)(struct ht_table*, const char*);
    int (*remove)(struct ht_table*, const char*);
} ht_table;

ht_item* ht_new_item(const char* k, const char* v);
ht_table* ht_new(int strategy);
void ht_del_item(ht_item* i);

int ht_set(ht_table* htable, ht_item* item);
ht_item* ht_get(ht_table* htable, const char* key);
int ht_remove(ht_table* htable, const char* key);

int ht_hash(const char* key);

#endif
