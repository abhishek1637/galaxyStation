/**
 * Count number of nodes in a generic Tree
 */

#include<iostream>
#include "helper/treeNode.h"

using namespace std;

int countNodes(TreeNode<int>* root) {
  if (root == NULL) {
    return 0;
  }

  int count = 1;

  for(int i = 0; i < root->children.size(); i++) {
    count += countNodes(root->children[i]);
  }

  return count;
}