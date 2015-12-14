#include "single_ll.h"

#include <stdio.h>
#include <stdlib.h>

struct SListNodeT {
    int elem;
    struct SListNodeT *next;
}; 

// Insert element into linked list,
// creates a new list if SListNode is NULL.
// Returns root of list if successful, NULL otherwise
SListNode *insert_slist(SListNode *l, int i) {
    if (l == NULL) {
        if ((l = malloc(sizeof (SListNode))) == NULL) {
            return NULL;
        } else {
            l->elem = i;
            l->next = NULL;   
            return l;
        }   
    
    } else {
        SListNode *res = insert_slist(NULL, i);
        SListNode *node = l;
        while (node->next != NULL) {
            node = node->next;
        }
        if (res == NULL) {
            return NULL;
        } else {
            node->next = res;
            return l;
       }
    }
}

// Delete the linked list
void delete_slist(SListNode *s) {
    if (s == NULL) {
        return;
    } else {
        SListNode* next = s->next;    
        free(s);
        delete_slist(next);
    }
}

void print_slist(SListNode *s) {
    printf("%s", "[");
    while (s != NULL) {
        printf("%i", s->elem);
        if (s->next != NULL) {
            printf("%s",",");
        } 
        s = s->next;
    }
    printf("%s", "]\n");
}

