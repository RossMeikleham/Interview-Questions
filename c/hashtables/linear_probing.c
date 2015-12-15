#include "linear_probing.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct BucketT {
    bool empty;
    int key;
    void *val;
} Bucket;


struct Probe_HTableT {
    unsigned size;
    Bucket *buckets;
    hash_fn hash;
};


// Creates a HashTable with a given size
Probe_HTable *create_phtable(unsigned size, hash_fn h) {
    Probe_HTable *c = malloc(sizeof (Probe_HTable));
    if (c != NULL) {
        Bucket *buckets = malloc(size * (sizeof (Bucket)));
        if (buckets != NULL) {
            c->size = size;
            c->hash = h;
            for (unsigned i = 0; i < size; i++) {
                buckets[i].empty = true;
            }
            c->buckets = buckets;
        } else {
            free(c);
        }
    }
    return c;
}


// Attempts to insert an element into
// the given HashTable, returns 1 if
// successful, 0 otherwise
int insert_phtable(Probe_HTable *t, int key, void *val) {
    int n;
    n = t->hash(key, t->size);
    if (n < t->size) {
        Bucket *previous = NULL;
        
        int i = n;
        do {
            Bucket *bucket = t->buckets + n;
          
            // If duplicate keys, fail
            // to insert 
            if (bucket->empty == true && bucket->key == key) {
                return 0;    
            }
            
            if (bucket->empty == true) {
                bucket->val = val;
                bucket->key = key;   
                bucket->empty = false; 
                return 1;
           }
        
            i = (i + 1) % t->size;   
        } while (i != n);
    }
    return 0;
}


// Attempts to find the element which
// corresponds to the given key from the
// table. Returns 1 if item is found, and the 
// res field stores the element, 0 if the
// key is not present in the table
int find_phtable(Probe_HTable *t, int key, void **res) {
    int n;
    n = t->hash(key, t->size);   
    int i = n; 
       
    do {
        Bucket *bucket = t->buckets + n;
        if (bucket->empty == false && key == bucket->key) {
            *res = bucket->val;
            return 1; 
        }
        i = (i + 1) % t->size;
    } while (n != i);

    return 0;
}


// Attempts to remove the element which
// corresponds to the given key from the
// table. Returns 1 if item is found, and the 
// res field stores the element, 0 if the
// key is not present in the table
int remove_phtable(Probe_HTable *t, int key, void **res) {
    int n;
    n = t->hash(key, t->size);   
    int i = n; 
       
    do {
        Bucket *bucket = t->buckets + n;
        if (bucket->empty == false && key == bucket->key) {
            *res = bucket->val;
            bucket->empty = true;
            return 1; 
        }
        i = (i + 1) % t->size;
    } while (n != i);

    return 0;
}


// Delete the given Hash Table
void delete_phtable(Probe_HTable *c) {
    if (c != NULL) {
        free(c->buckets);
        free(c); 
    }  
}


void print_phtable_int(Probe_HTable *t) {
   printf("%s", "Table:\n");
   if (t != NULL) {
       for (unsigned i = 0; i < t->size; i++) {
           Bucket *bucket = t->buckets + i;
           if (!bucket->empty) {
            printf("%d: key: %d, val: %d\n", i, bucket->key, *(int *)(bucket->val));
           }       
       }
   } 
}

