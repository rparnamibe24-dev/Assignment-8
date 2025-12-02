#include <iostream>
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

Node* insert(Node* root, int data) {
    if (root == nullptr) return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

Node* findMinNode(Node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return nullptr;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// (c) Maximum Depth (Height)
int maxDepth(Node* root) {
    if (root == nullptr) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// (d) Minimum Depth
int minDepth(Node* root) {
    if (root == nullptr) return 0;
    if (!root->left && !root->right) return 1;

    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main() {
    Node* root = nullptr;

    root = insert(root, 30);
    insert(root, 20);
    insert(root, 10);
    insert(root, 25);
    insert(root, 40);
    insert(root, 50);

    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Min Depth: " << minDepth(root) << endl;

    cout << "Deleting 20...\n";
    root = deleteNode(root, 20);

    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Min Depth: " << minDepth(root) << endl;

    return 0;
}
