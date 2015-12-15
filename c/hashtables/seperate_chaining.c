#include "seperate_chaining.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct BucketT {
    bool empty;
    int key;
    void *val;
    struct BucketT *next;
} Bucket;


struct Chain_HTableT {
    unsigned size;
    Bucket **buckets;
    hash_fn hash;
};


// Creates a HashTable with a given size
Chain_HTable *create_chtable(unsigned size, hash_fn h) {
    Chain_HTable *c = malloc(sizeof (Chain_HTable));
    if (c != NULL) {
        Bucket **buckets = malloc(size * (sizeof (Bucket *)));
        if (buckets != NULL) {
            c->size = size;
            c->hash = h;
            for (unsigned i = 0; i < size; i++) {
                buckets[i] = false;
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
int insert_chtable(Chain_HTable *t, int key, void *val) {
    int n;
    n = t->hash(key, t->size);
    if (n < t->size) {
        Bucket *previous = NULL;
        Bucket *bucket = t->buckets[n];
        
        for (;;) {           
           // If end of the bucket list
           // create new bucket and add the key,val pair
           if (bucket == NULL) {
                bucket = malloc(sizeof (Bucket));
                if (bucket == NULL) {
                    return 0;
                }
                bucket->key = key;
                bucket->val = val;
                bucket->empty = false;
                bucket->next = NULL;
                if (previous == NULL) {
                    t->buckets[n] = bucket;
                } else {
                    previous->next = bucket;
                }
                return 1;
           } 

           
            if (bucket->empty == true) {
                bucket->val = val;
                bucket->key = key;   
                bucket->empty = false; 
                return 1;
           }
           
           // If bucket has the same key
           // fails to insert
           if (bucket->key == key) {
                return 0;    
           }
                
           previous = bucket;
           bucket = bucket->next;
        }
    }
    return 0;
}


// Attempts to find the element which
// corresponds to the given key from the
// table. Returns 1 if item is found, and the 
// res field stores the element, 0 if the
// key is not present in the table
int find_chtable(Chain_HTable *t, int key, void **res) {
    int n;
    n = t->hash(key, t->size);
    
    Bucket *bucket = t->buckets[n];
    for (;;) {
        if (bucket == NULL || bucket->empty) {
            return 0;
        }
        if (key == bucket->key) {
            *res = bucket->val;
            return 1; 
        }
        bucket = bucket->next; 
    }
}


// Attempts to remove the element which
// corresponds to the given key from the
// table. Returns 1 if item is found, and the 
// res field stores the element, 0 if the
// key is not present in the table
int remove_chtable(Chain_HTable *t, int key, void **res) {
    int n;
    n = t->hash(key, t->size);
    
    Bucket *previous = NULL;
    Bucket *bucket = t->buckets[n];
    Bucket *next = bucket == NULL ? NULL : bucket->next;
    for (;;) {
        if (bucket == NULL || bucket->empty) {
            return 0;
        }
        if (key == bucket->key) {
            *res = bucket->val;
            free(bucket);
            if (previous != NULL) {
                previous->next = next;
            } else {
                t->buckets[n] = next;
            }
            return 1; 
        }
        previous = bucket;
        bucket = bucket->next; 
        next = bucket == NULL ? NULL : bucket->next;
    }
}
    

void delete_bucket(Bucket *b) {
    while(b != NULL) {
        Bucket *next = b->next;
        free(b);
        b = next;
    }
}

// Delete the given Hash Table
void delete_chtable(Chain_HTable *c) {
    if (c != NULL) {
        for (int i = 0; i < c->size; i++) {
            delete_bucket(c->buckets[i]);    
        } 
        free(c); 
    }  
}


void print_bucket(Bucket *b, int i) {
    if (b == NULL) {
        return;
    }
       
    printf("%d: ", i);
    while(b != NULL) {
        printf("{key: %d, val: %d}", b->key, *((int *)b->val));
        if (b->next != NULL) {
            printf("%s", "->");
        }
        b = b->next;
    }
    printf("%s", "\n");
}

void print_chtable_int(Chain_HTable *t) {
   printf("%s", "Table:\n");
   if (t != NULL) {
       for (unsigned i = 0; i < t->size; i++) {
           print_bucket(t->buckets[i], i);        
       }
   } 
}

