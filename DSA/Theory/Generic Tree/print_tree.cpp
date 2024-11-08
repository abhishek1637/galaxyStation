/**
 * How to print a generic tree ?

    There are many ways to print a generic tree - preOrder, postOrder etc.
    But first, we will be printing in a fashionable way such that it will be clear from output if a node
    has a child or not, if it has a child then which are the children of the node.
 */

#include<iostream>
#include <vector>

#include "treeNode_class.cpp"

using namespace std;

void printTree(TreeNode<int>* root) {
  // edge cases
  if (root == NULL) {
    return;
  }

  cout << root->data << ":";

  for (int i=0; i< root->children.size(); i++) {
    cout << root->children[i]->data << ",";
  }

  cout << endl;

  for (int i=0; i < root->children.size(); i++) {
    printTree(root->children[i]);
  }
}

// int main () {
//     TreeNode<int>* root = new TreeNode<int>(1);
//     TreeNode<int>* node1 = new TreeNode<int>(2);
//     TreeNode<int>* node2 = new TreeNode<int>(3);
    
//     root->children.push_back(node1);
//     root->children.push_back(node2);

//     printTree(root);
// }