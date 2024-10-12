/**
 * How to take input level wise ?
 * To take input level wise, we will be putting each element in a queue. 
 * Then, we will be checking each element and its child one by one.
 * Put its child in the queue and delete that element from the queue.
 */

#include <iostream>
#include <queue>
#include "take_input.cpp"

using namespace std;

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;

    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of children of " << front->data << endl;
        int numChild;
        cin >> numChild;

        for (int i= 0; i < numChild; i++) {
            int childData;
            cout << "Enter " << i << " child of " << front->data << endl;
            cin >> childData;

            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

