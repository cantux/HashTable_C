#ifndef HT_SIMPLE_STRAT_H
#define HT_SIMPLE_STRAT_H

#include "ht.h"

ht_item* ht_simple_get(ht_table* ht, const char* key);
int ht_simple_set(ht_table* ht, ht_item* item);

#endif

