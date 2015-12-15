// Linear Probing Hash Table Implementation

#ifndef LIN_PROBING_H
#define LIN_PROBING_H

typedef struct Probe_HTableT Probe_HTable;

typedef int (*hash_fn)(int key, int size);

// Creates a HashTable with a given size
Probe_HTable *create_phtable(unsigned size, hash_fn h);

// Attempts to insert an element into
// the given HashTable, returns 1 if
// successful, 0 otherwise
int insert_phtable(Probe_HTable *t, int key, void *val); 

// Attempts to find the element which
// corresponds to the given key from the
// table. Returns 1 if item is found, and the 
// res field stores the element, 0 if the
// key is not present in the table
int find_phtable(Probe_HTable *t, int ket, void **res);


// Attempts to remove the element which
// corresponds to the given key from the
// table. Returns 1 if item is found, and the 
// res field stores the element, 0 if the
// key is not present in the table
int remove_phtable(Probe_HTable *t, int key, void **res);


// Delete the given Hash Table
void delete_phtable(Probe_HTable *c);


void print_phtable_int(Probe_HTable *t);

#endif
