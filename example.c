#include <stdio.h>
#include "src/hashtable.c"

int main() {
  Hashtable* hashtable = create_hashtable(100000);

  table_add(hashtable, "key", "value");
  table_add(hashtable, "beans", "cheese");


  char* value = table_get(hashtable, "key");
  char* value2 = table_get(hashtable, "beans");

  printf("Value: %s, %s\n", value, value2);

  int remove = table_remove(hashtable, "beans");
  char* value3 = table_get(hashtable, "beans");
  printf("Value after being removed: %s\n", value3);

  free_hashtable(hashtable);
}

