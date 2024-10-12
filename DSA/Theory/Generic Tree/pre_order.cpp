/**
 * Traversal in pre-order
 * print root node first then left then right
 */

#include <iostream>
#include "print_tree_level_wise.cpp"

using namespace std;

void preOrder(TreeNode<int>* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    
    for (int i=0; i< root->children.size(); i++) {
        preOrder(root->children[i]);
    }
}
