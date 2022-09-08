#include <iostream>

struct TreeNode {
    int info;
    TreeNode* left, * right;
};
class BinSearchTree {
public:
    BinSearchTree(int input[], int size) {
        root = buildTree(input, 0, size); // this calls your method
    }
    void traverseNodes(TreeNode* root);
    void traverseNodes();
private:
    TreeNode* root = nullptr;
    /**
     * Builds a binary using the elements from input[start]
     * to input[end]. So start and end are indices for the array input
     */
    TreeNode* buildTree(int input[], int start, int end);
};

void BinSearchTree::traverseNodes() {
    traverseNodes(root); // call the traversal with the root, which is private
}

void BinSearchTree::traverseNodes(TreeNode* root) {
    if (root == nullptr)
        return;
    traverseNodes(root->left);
    std::cout << root->info << " ";
    traverseNodes(root->right);
}


/**
     * Builds a binary using the elements from input[start]
     * to input[end]. So start and end are indices for the array input
*/
TreeNode* BinSearchTree::buildTree(int input[], int start, int end) {
    int mid;
    if (start > end) return nullptr;    // base case (stops infinite recursion)
    mid = (start + end) / 2;
    TreeNode* myNode = new TreeNode;
    myNode->info = input[mid];          // sets parent info
    myNode->left = buildTree(input, start, mid-1);
    myNode->right = buildTree(input, mid+1, end);
    return myNode;  // returns each node
}


int main() {
    int input[] = { 4, 9, 15, 20, 22, 24, 35, 87 };
    //1 - create the binary search tree given the sorted input 
    BinSearchTree st = BinSearchTree(input, 7);
    //2 - print the tree node values inorder
    std::cout << "Tree node values in order: ";
    st.traverseNodes(); // this code was given on Canvas earlier
}