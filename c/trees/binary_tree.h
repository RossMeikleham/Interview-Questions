#ifndef bintree_H
#define bintree_H

typedef struct TreeNodeT TreeNode;

// Insert element into binary tree,
// creates a new tree if treeNode is NULL.
// Returns the root of the tree.
// If malloc unsuccessful then returns NULL.
TreeNode *insert_tree (TreeNode *t, int i);

// Delete the binary tree
void delete_tree(TreeNode *t);

void print_tree(TreeNode *t);

#endif
