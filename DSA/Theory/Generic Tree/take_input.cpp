/**
 * In this topic, we will learn how can we take input from user and build a tree
 */

#include<iostream>
#include "print_tree.cpp"

using namespace std;

TreeNode<int>* takeInput() {
  int rootData;
  cout << "Enter Data: ";
  cin >> rootData;

  TreeNode<int>* root = new TreeNode<int>(rootData);

  int n;
  cout << "Enter number of children of " << rootData << endl;
  cin >> n;

  for (int i=0; i<n; i++) {
    TreeNode<int>* child = takeInput();
    root->children.push_back(child);
  }

  return root;
}
