// A. Create Binary tree and perform following operations:
// a. Insert
// b. Display
// c. Find Depth of a tree
// d. Display leaf-nodes
// e. Create a copy of a tree.

// Enter the number of nodes: 7
// Enter the values of the nodes:
// 50 30 70 20 40 60 80
// Enter the number of nodes: 7
// Enter the values of the nodes:
// 50 30 70 20 40 60 80

// Tree in-order display: 20 30 40 50 60 70 80
// Depth of tree: 2
// Leaf nodes: 20 40 60 80
// Copied tree in-order display: 20 30 40 50 60 70 80

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* createNode(int key) {
    Node* newNode = new Node();
    newNode->value = key;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void display(Node* root) {
    if (root != nullptr) {
        display(root->left);
        cout << root->value << " ";
        display(root->right);
    }
}

int findDepth(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

void displayLeafNodes(Node* root) {
    if (root == nullptr) {
        return;
    }
    if (root->left == nullptr && root->right == nullptr) {
        cout << root->value << " ";
    }
    displayLeafNodes(root->left);
    displayLeafNodes(root->right);
}

Node* createCopy(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    Node* newNode = createNode(root->value);
    newNode->left = createCopy(root->left);
    newNode->right = createCopy(root->right);
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

int main() {
    Node* root = nullptr;
    int n, value;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the values of the nodes:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        root = insertNode(root, value);
    }

    cout << "\nTree in-order display: ";
    display(root);
    cout << endl;

    cout << "Depth of tree: " << findDepth(root) - 1 << endl;

    cout << "Leaf nodes: ";
    displayLeafNodes(root);
    cout << endl;

    Node* rootCopy = createCopy(root);
    cout << "Copied tree in-order display: ";
    display(rootCopy);
    cout << endl;

    return 0;
}
