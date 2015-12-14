#include "binary_tree.h"

#include <stdlib.h>

void test_bin_tree() {
    TreeNode *root = NULL;
    root = insert_tree(root, 1);
    insert_tree(root, 2);
    insert_tree(root, 4);
    insert_tree(root, 3);
    
    print_tree(root);
    delete_tree(root);
    root = NULL;
    print_tree(root);  
}

int main(int argc, char *argv[]) {
   test_bin_tree(); 
}

