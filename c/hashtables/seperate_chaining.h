// Seperate Chaining Hash Table Implementation

#ifndef SEPERATE_CHAIN_H
#define SEPERATE_CHAIN_H

typedef struct Chain_HTableT Chain_HTable;

typedef int (*hash_fn)(int key, int size);

// Creates a HashTable with a given size
Chain_HTable *create_chtable(unsigned size, hash_fn h);

// Attempts to insert an element into
// the given HashTable, returns 1 if
// successful, 0 otherwise
int insert_chtable(Chain_HTable *t, int key, void *val); 

// Attempts to find the element which
// corresponds to the given key from the
// table. Returns 1 if item is found, and the 
// res field stores the element, 0 if the
// key is not present in the table
int find_chtable(Chain_HTable *t, int ket, void **res);


// Attempts to remove the element which
// corresponds to the given key from the
// table. Returns 1 if item is found, and the 
// res field stores the element, 0 if the
// key is not present in the table
int remove_chtable(Chain_HTable *t, int key, void **res);


// Delete the given Hash Table
void delete_chtable(Chain_HTable *c);


void print_chtable_int(Chain_HTable *t);

#endif
