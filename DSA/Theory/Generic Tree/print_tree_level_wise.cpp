/**
 * How to print a tree in a level ?
 * We will be using queue to put each element in it and pop and print its children.
 */

#include <iostream>
#include <queue>

#include "take_input_level_wise.cpp"

using namespace std;

void printTreeLevelWise(TreeNode<int>* root) {
    if (root == NULL) {
        return;
    }

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {
        TreeNode<int>* node = pendingNodes.front();
        pendingNodes.pop();

        cout << node->data << ":" ;

        for (int i = 0; i < node->children.size(); i++) {
            pendingNodes.push(node->children[i]);

            if (i !=0 ) {
                cout << ",";
            }

            cout << node->children[i]->data;
        }
        cout << endl;
    }

}