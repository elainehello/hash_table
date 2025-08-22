#include "hash_table.h"
#include <stdio.h>

/**
 * main - Entry point for testing the hash table implementation.
 * @param argc: Argument count.
 * @param argv: Argument vector.
 * @return: 0 on success.
 */
int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    t_hash *ht = create_table(5);

    insert(ht, 10);
    insert(ht, 15);
    insert(ht, 20);

    printf("Search 15: %s\n", search(ht, 15) ? "Found" : "Not found");
    printf("Search 99: %s\n", search(ht, 99) ? "Found" : "Not found");

    delete(ht, 15);
    printf("Search 15 after delete: %s\n", search(ht, 15) ? "Found" : "Not found");

    free_hash(ht);
    return (0);
}