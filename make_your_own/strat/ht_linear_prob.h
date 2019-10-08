#ifndef HT_LINEAR_PROB_H
#define HT_LINEAR_PROB_H

#include "ht.h"

ht_item* ht_linear_get(ht_table* ht, const char* key);
int ht_linear_set(ht_table* ht, ht_item* item);
int ht_linear_remove(ht_table* htable, const char* key);

#endif

