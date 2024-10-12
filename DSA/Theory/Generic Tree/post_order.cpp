/**
 * Traverse the tree in post order
 * first print left child, then right child and at last root.
 */

#include <iostream>
#include "pre_order.cpp"

using namespace std;

void postOrder(TreeNode<int>* root) {
    if (root == NULL) {
        return;
    }

    for (int i=0; i < root->children.size(); i++) {
        postOrder(root->children[i]);
    }

    cout << root->data << " ";
}