/**
 * How can we delete a tree.
 * we can either define a func and call it.
 * Else, we can use of destructor
 * we can find destructor code in treeNode_class.cpp file.
 * We can't directly use delete root. it will delete the root node but all other node will still exist in memory.
 * after writing destructor code, it can delete all node one by one when we use - delete root.
 */

#include <iostream>
#include "post_order.cpp"

using namespace std;

void deleteTree(TreeNode<int>* root) {
    for (int i=0; i< root->children.size(); i++) {
        deleteTree(root->children[i]);
    }

    delete root;
}