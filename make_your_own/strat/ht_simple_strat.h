#ifndef HT_SIMPLE_STRAT_H
#define HT_SIMPLE_STRAT_H

#include "ht.h"

ht_item* ht_simple_get(ht_table* htable, const char* key);
int ht_simple_set(ht_table* htable, ht_item* item);
int ht_simple_remove(ht_table* htable, const char* key);

#endif

