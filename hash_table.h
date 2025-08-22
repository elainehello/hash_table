#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <limits.h>
#include <stdlib.h>

typedef struct s_node
{
    int data;
    struct s_node *next;
} t_node;

typedef struct s_hash
{
    int size;
    t_hash **hash;
} t_hash;

// Function prototypes
t_hash *create_table(int size);
int hash(t_hash *ht, int key);
void insert(t_hash *ht, int key);
int search(t_hash *ht, int key);
void delete(t_hash *ht, int key);
void display(t_hash *ht);
void free_hash(t_hash *ht);

#endif