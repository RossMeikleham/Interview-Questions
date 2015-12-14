#ifndef SINGLE_LL_H
#define SINGLE_LL_H

typedef struct SListNodeT SListNode;


// Insert element into linked list,
// creates a new list if SListNode is NULL.
// Returns 1 if successful, 0 otherwise
SListNode *insert_slist(SListNode *l, int i);

// Delete the linked list
void delete_slist(SListNode *s);

void print_slist(SListNode *s);

#endif
