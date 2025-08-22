#include "hash_table.h"

t_hash *create_table(int size)
{
    t_hash *hash;

    hash = malloc(sizeof(t_hash));
    if (hash == NULL)
        return NULL;
    hash->size = size;
    hash->hash = malloc(sizeof(t_node *) * size);
    if (hash->hash == NULL)
        return (free(hash), NULL);
    init_bucket(hash);
    return (hash);
}

void init_bucket(t_hash *hash)
{
    int i;

    i = 0;
    while (i < hash->size)
    {
        hash->hash[i] = NULL;
        i++;
    }
}

int hash(t_hash *ht, int key)
{
    return (key % ht->size);
}

t_node *create_node(int key)
{
    t_node *new_node;

    new_node = malloc(sizeof(t_node));
    if (new_node == NULL)
        return NULL;
    new_node->data = key;
    new_node->next = NULL;
    return (new_node);
}

void insert(t_hash *ht, int key)
{
    int     idx;
    t_node  *new_node;

    if (ht == NULL)
        return ;
    idx = hash(ht, key);
    new_node = create_node(key);
    if (new_node == NULL)
        return ; 
    new_node->next = ht->hash[idx];
    ht->hash[idx] = new_node;
}
int search(t_hash *ht, int key)
{

}
void delete(t_hash *ht, int key)
{

}
void display(t_hash *ht)
{

}
void free_hash(t_hash *ht)
{

}
