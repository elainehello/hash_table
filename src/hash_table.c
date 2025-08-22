#include "hash_table.h"

/**
 * create_table - Allocates and initializes a new hash table.
 * @param size: The number of buckets in the hash table.
 * @return: Pointer to the created hash table, or NULL on failure.
 */
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

/**
 * init_bucket - Initializes all buckets in the hash table to NULL.
 * @param hash: Pointer to the hash table.
 */
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

/**
 * hash - Computes the hash index for a given key.
 * @param ht: Pointer to the hash table.
 * @param key: The key to hash.
 * @return: The computed index.
 */
int hash(t_hash *ht, int key)
{
    return (key % ht->size);
}

/**
 * create_node - Allocates and initializes a new node with the given key.
 * @param key: The key to store in the node.
 * @return: Pointer to the created node, or NULL on failure.
 */
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

/**
 * insert - Inserts a key into the hash table.
 * @param ht: Pointer to the hash table.
 * @param key: The key to insert.
 */
void insert(t_hash *ht, int key)
{
    int idx;
    t_node *new_node;

    if (ht == NULL)
        return;
    idx = hash(ht, key);
    new_node = create_node(key);
    if (new_node == NULL)
        return;
    new_node->next = ht->hash[idx];
    ht->hash[idx] = new_node;
}

/**
 * search - Searches for a key in the hash table.
 * @param ht: Pointer to the hash table.
 * @param key: The key to search for.
 * @return: 1 if found, 0 otherwise.
 */
int search(t_hash *ht, int key)
{
    int idx;
    t_node *curr;

    if (ht == NULL)
        return (0);
    idx = hash(ht, key);
    curr = ht->hash[idx];
    while (curr)
    {
        if (curr->data == key)
            return (1);
        curr = curr->next;
    }
    return (0);
}

/**
 * delete - Removes a node with the given key from the hash table.
 * @param ht: Pointer to the hash table.
 * @param key: The key to be deleted.
 *
 * Iterates through the linked list at the hashed index to find the node
 * with the matching key. If found, updates the previous node's next pointer
 * (or the head pointer if it's the first node) to skip the deleted node,
 * then frees the memory for the deleted node.
 */
void delete(t_hash *ht, int key)
{
    int idx;
    t_node *curr;
    t_node *prev;

    if (ht == NULL)
        return;
    idx = hash(ht, key);
    curr = ht->hash[idx];
    prev = NULL;
    while (curr)
    {
        if (curr->data == key)
        {
            if (prev)
                prev->next = curr->next;
            else
                ht->hash[idx] = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

/**
 * free_hash - Frees all memory used by the hash table and its nodes.
 * @param ht: Pointer to the hash table to be freed.
 */
void free_hash(t_hash *ht)
{
    int i;
    t_node *curr;
    t_node *tmp;

    if (ht == NULL)
        return;
    i = 0;
    while (i < ht->size)
    {
        curr = ht->hash[i];
        while (curr)
        {
            tmp = curr;
            curr = curr->next;
            free(tmp);
        }
        i++;
    }
    free(ht->hash);
    free(ht);
}
