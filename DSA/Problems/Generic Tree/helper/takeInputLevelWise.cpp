#include <iostream>
#include <queue>

#include "treeNode.cpp"

using namespace std;

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "Enter the root data: ";
    cin >> rootData;

    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        int numChild;

        cout << "Enter the number of child of " << front->data << " : ";
        cin >> numChild;

        for (int i = 0; i < numChild; i++) {
            int childData;

            cout << "Enter " << i << " child of " << front->data << " : ";
            cin >> childData;

            TreeNode<int>* child = new TreeNode<int>(childData);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}