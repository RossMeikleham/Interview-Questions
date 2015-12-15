#ifndef redblacktree_H
#define redblacktree_H

typedef struct RBTreeNodeT RBTreeNode;


RBTreeNode *create_RBtree(int i);

// Insert element into binary tree,
// creates a new tree if treeNode is NULL.
// Returns the root of the tree.
// If malloc unsuccessful then returns NULL.
RBTreeNode *insert_RBtree (RBTreeNode *t, int i);

// Delete the binary tree
void delete_RBtree(RBTreeNode *t);

void print_RBtree(RBTreeNode *t);

#endif
