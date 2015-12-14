#include "binary_tree.h"

#include <stdlib.h>
#include <stdio.h>

struct TreeNodeT {
    int elem;
    TreeNode* left;
    TreeNode* right; 
};

//Insert item into binary tree
TreeNode *insert_tree (TreeNode *t, int i) {
   if (t == NULL) {
    t = malloc(sizeof (TreeNode));
    t->elem = i;
    t->left = NULL;
    t->right = NULL;
    return t;
   }
      
   if (t->elem > i) {
        t->left = insert_tree(t->left, i);
   } else {
        t-> right = insert_tree(t->right, i);   
   } 

   return t;
}


// Delete the binary tree
void delete_tree(TreeNode *t) {
    if(t == NULL) {
        return;
    }
    if (t->left != NULL) {
        delete_tree(t->left);
    }
    if (t->right != NULL) {
        delete_tree(t->right);
    }
    free(t);
}

void print_tree_2(TreeNode *t) {
    printf("%s", "[");
    if (t != NULL) {
        printf("%d, ", t->elem);
        print_tree_2(t->left);
        print_tree_2(t->right);
    } else {
        printf("%s", "NULL");
    }
    printf("%s", "]");   
}   

void print_tree(TreeNode *t) {
    print_tree_2(t);
    printf("%s", "\n");
}

