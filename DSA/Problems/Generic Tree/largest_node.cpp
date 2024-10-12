/**
 * Find the largest node in a tree
 */

#include<iostream>

#include "helper/treeNode.h"

using namespace std;

TreeNode<int>* largestNode(TreeNode<int>* root) {
  if (root == NULL) {
    return root;
  }

  TreeNode<int>* max = root;

  for (int i=0; i < root->children.size(); i++) {
    TreeNode<int>* maxChild = largestNode(root->children[i]);
    if (max->data < maxChild->data) {
      max = maxChild;
    }
  }

  return max;
}