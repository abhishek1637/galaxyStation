#include <iostream>

#include "helper/preOrder.cpp"
#include "helper/takeInputLevelWise.cpp"

#include "countNodes.cpp"
#include "sum_of_nodes.cpp"
#include "largest_node.cpp"
#include "heightOfTree.cpp"
#include "depthOfTree.cpp"
#include "numOfLeafNodes.cpp"

using namespace std;

int main() {
    // input -> 1 3 2 3 4 2 5 6 0 1 9 0 2 7 8 0 0 0
    TreeNode<int>* root = takeInputLevelWise();
    preOrder(root);
    cout << endl;

    cout << "Total number of nodes in tree: " <<  countNodes(root) << endl;
    cout << "Sum of nodes : " << sumOfNodes(root) << endl;
    cout << "Largest node in the tree : " << largestNode(root)->data << endl;
    cout << "Height of the tree : " << getHeight(root) << endl;
    cout << "Depth of the tree at level 2 : " << endl;
    printAtLevelK(root, 2);

    cout << "Number of leaf nodes in the tree: " << numOfLeafNodes(root) << endl;

    cout << endl;
}