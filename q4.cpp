#include <iostream>
#include <limits.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* n = new Node;
    n->data = data;
    n->left = n->right = nullptr;
    return n;
}

// Helper function
bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == nullptr) return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = createNode(20);
    root->left = createNode(10);
    root->right = createNode(30);
    root->left->left = createNode(5);

    if (isBST(root))
        cout << "Tree IS a BST\n";
    else
        cout << "Tree is NOT a BST\n";

    return 0;
}
