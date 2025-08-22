# Hash Table Library

A simple C implementation of a hash table with basic operations: insert, search, delete, and free.

## Structure

```
.
├── include
│   └── hash_table.h
├── src
│   ├── hash_table.c
│   └── hash_table.o
├── main.c
├── Makefile
└── libhashtable.a
```

## Building

To build the static library and the test executable:

```sh
make        # Builds the library (libhashtable.a)
make test   # Builds the test executable (hashtable_test)
```

Or, to build both by default, update the `all` target in the Makefile to:

```
all: $(NAME) $(EXEC)
```

## Usage

Include the header in your C files:

```c
#include "hash_table.h"
```

Link against the library when compiling:

```sh
gcc -Iinclude main.c libhashtable.a -o myprog
```

## API

- `t_hash *create_table(int size);`  
  Create a new hash table.

- `void insert(t_hash *ht, int key);`  
  Insert a key.

- `int search(t_hash *ht, int key);`  
  Search for a key.

- `void delete(t_hash *ht, int key);`  
  Delete a key.

- `void free_hash(t_hash *ht);`  
  Free the hash table.

## Example

See `main.c` for a usage example.

## Cleaning

```sh
make clean   # Remove object files
make fclean  # Remove object files, library, and executable
make re      # Rebuild everything
```
