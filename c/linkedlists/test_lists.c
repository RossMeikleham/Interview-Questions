#include "single_ll.h"

#include <stdlib.h>

void test_single_ll() {
   SListNode *root = NULL;
   root = insert_slist(root, 4);
   insert_slist(root, 10);
   insert_slist(root, 12);
   insert_slist(root, 27);
   
   print_slist(root);
   
   delete_slist(root);
   root = NULL;
   print_slist(root);   
}

int main(int argc, char *argv[]) {
    test_single_ll();
}
