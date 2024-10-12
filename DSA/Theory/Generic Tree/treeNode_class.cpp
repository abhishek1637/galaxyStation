/*
A tree is a non-liner ds. There is one root and it can have multiple children. To store all the children, 
we need an array of Tree class as each child is again a root for its children. 
For better and easy way, we will use vector.
*/

#include <vector>
using namespace std;

template <typename T>

/*
   Tree Node Class to represent a node - a node can be a root node or any child node
*/
class TreeNode {
    public:
        T data;
        vector<TreeNode *> children;

        TreeNode(T data) {
            this->data = data;
        }
};

// int main () {
//     TreeNode<int>* root = new TreeNode<int>(1);
//     TreeNode<int>* node1 = new TreeNode<int>(2);
//     TreeNode<int>* node2 = new TreeNode<int>(3);
    
//     root->children.push_back(node1);
//     root->children.push_back(node2);
// }