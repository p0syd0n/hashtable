
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/hashtable.c" // your library

#define ENTRIES 5000000
#define SIZE 10000000

// chatgpt wrote this code. I will never write tests
int main() {
    srand(time(NULL));
    Hashtable* table = create_hashtable(SIZE);

    int inserts = 0;
    int gets = 0;
    int updates = 0;
    int removals = 0;

    // Insert ENTRIES random key-value pairs
    for (int i = 0; i < ENTRIES; i++) {
        char key[32];
        char value[32];
        snprintf(key, sizeof(key), "key%d", i);
        snprintf(value, sizeof(value), "value%d", i);

        if (table_add(table, key, value) == 0) {
            inserts++;
        }
    }

    printf("Inserted\n");

    // Get half of them (DON’T free results here)
    for (int i = 0; i < ENTRIES / 2; i++) {
        char key[32];
        snprintf(key, sizeof(key), "key%d", rand() % ENTRIES);

        char* result = table_get(table, key);
        if (result != NULL) {
            gets++;
            // Do not free(result) here!
            // If you want, you can store results in an array to reuse later.
        }
    }
    printf("Getted\n");

    // Update some entries
    for (int i = 0; i < ENTRIES / 4; i++) {
        char key[32];
        char value[32];
        snprintf(key, sizeof(key), "key%d", rand() % ENTRIES);
        snprintf(value, sizeof(value), "updated%d", i);

        if (table_add(table, key, value) == 0) {
            updates++;
        }
    }
    printf("Updated\n");


    // Remove some entries
    for (int i = 0; i < ENTRIES / 4; i++) {
        char key[32];
        snprintf(key, sizeof(key), "key%d", rand() % ENTRIES);

        if (table_remove(table, key) == 0) {
            removals++;
        }
    }

    printf("removed\n");

    printf("Stress Test Summary:\n");
    printf("Inserts: %d\n", inserts);
    printf("Gets: %d\n", gets);
    printf("Updates: %d\n", updates);
    printf("Removals: %d\n", removals);

    return 0;
}
