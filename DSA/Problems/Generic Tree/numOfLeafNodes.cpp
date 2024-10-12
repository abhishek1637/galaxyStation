/**
 * Count the number of leaf nodes in a tree
*/

#include<iostream>
#include "helper/treeNode.h"

using namespace std;

int numOfLeafNodes(TreeNode<int>* root) {
  if (root == NULL) {
    return 0;
  }

  if (root->children.size() == 0) {
    return 1;
  }

  int sum = 0;

  for (int i=0; i < root->children.size(); i++) {
    sum += numOfLeafNodes(root->children[i]);
  }
  return sum;
}
