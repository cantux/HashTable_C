#include "stdio.h"
#include "stdlib.h"

#include "ht.h"

int main(void) {
  ht_table* t = ht_new(SIMPLE_STRAT);
  if(!t) {
    return -1;
  }
  
  ht_item* item = ht_new_item("hello", "goodbye");

  ht_set(t, item);
  ht_item* found = ht_get(t, "hello");
  printf("key: %s, value: %s\n", found->key, found->value);

  ht_table* l_t = ht_new(LINEAR_PROBING);
  ht_item* first = ht_new_item("first", "first_value");
  ht_set(l_t, first);
  ht_item* res = ht_get(l_t, "first");
  if(res) {
    printf("expected first_value got: %s\n", res->value);
  }
  else {
    printf("item not in hash\n");
    return -1;
  }
  
  return 0;
}
