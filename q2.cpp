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

// (a) Search (Recursive)
Node* searchRec(Node* root, int key) {
    if (root == nullptr || root->data == key) return root;

    if (key < root->data)
        return searchRec(root->left, key);
    else
        return searchRec(root->right, key);
}

// (a) Search (Iterative)
Node* searchItr(Node* root, int key) {
    while (root != nullptr) {
        if (root->data == key) return root;
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return nullptr;
}

// (b) Max element
int findMax(Node* root) {
    while (root->right != nullptr)
        root = root->right;
    return root->data;
}

// (c) Min element
int findMin(Node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root->data;
}

// (d) In-order successor
Node* inorderSuccessor(Node* root, int key) {
    Node* current = searchRec(root, key);
    if (!current) return nullptr;

    if (current->right != nullptr) {
        Node* temp = current->right;
        while (temp->left)
            temp = temp->left;
        return temp;
    }

    Node* successor = nullptr;
    Node* ancestor = root;

    while (ancestor != current) {
        if (current->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }

    return successor;
}

// (e) In-order predecessor
Node* inorderPredecessor(Node* root, int key) {
    Node* current = searchRec(root, key);
    if (!current) return nullptr;

    if (current->left != nullptr) {
        Node* temp = current->left;
        while (temp->right)
            temp = temp->right;
        return temp;
    }

    Node* predecessor = nullptr;
    Node* ancestor = root;

    while (ancestor != current) {
        if (current->data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }

    return predecessor;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 30);
    insert(root, 25);
    insert(root, 40);

    cout << "Min element: " << findMin(root) << endl;
    cout << "Max element: " << findMax(root) << endl;

    Node* succ = inorderSuccessor(root, 15);
    Node* pred = inorderPredecessor(root, 15);

    cout << "Successor of 15: " << (succ ? succ->data : -1) << endl;
    cout << "Predecessor of 15: " << (pred ? pred->data : -1) << endl;

    return 0;
}
