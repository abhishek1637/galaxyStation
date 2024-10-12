/**
 * Find the height of the tree. Height is the maximum length from root to the last child
*/

#include<iostream>
#include "helper/treeNode.h"

using namespace std;

int getHeight(TreeNode<int>* root) {
  if (root == NULL) {
    return 0;
  }

  int height = 1;
  for (int i=0; i < root->children.size(); i++) {
    int childHeight = getHeight(root->children[i]) + 1;
    if (height < childHeight) {
      height = childHeight;
    }
  }

  return height;
}