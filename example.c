#include <stdio.h>
#include "src/hashtable.c"

int main() {
  Hashtable* hashtable = create_hashtable(100000); // This will be enough to contain 100,000 seperate elements. However, it is also 800 kilobytes in ram.

  table_add(hashtable, "key", "value");
  table_add(hashtable, "beans", "cheese");


  char* value = table_get(hashtable, "key");
  char* value2 = table_get(hashtable, "beans");
  /*
  Do not free these. Otherwise, you will be left with dangling pointers. If you want to be able to free them, find the line in hashtable.c in table_get and make it say return strdup(node->value); and not return node->value; .  This will, however, make things slower. 
  */ 

  printf("Value: %s, %s\n", value, value2);

  int remove = table_remove(hashtable, "beans");
  char* value3 = table_get(hashtable, "beans");
  printf("Value after being removed: %s\n", value3); //  This should be (nil) or wtv

  free_hashtable(hashtable); // Pls free it. It wants freedom. I stand in support of hashtableian abolitionism
}

