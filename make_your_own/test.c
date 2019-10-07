#include "stdio.h"

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


  return 0;
}
