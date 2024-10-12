/**
 * This file contains the main func of the Generic tree.
 * Here, we will be importing each class and print it.
 * So, this main class is the super main of all the classes
 */

#include<iostream>
#include "print_tree_level_wise.cpp"

using namespace std;

int main () {
    TreeNode<int>* root = takeInputLevelWise();
    printTreeLevelWise(root);
}