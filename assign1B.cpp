// B. Implement binary search tree and perform following operations:
// a. Insert b. Delete c. Display d. Search e. BFS (Level wise print)

#include <iostream>
#include <queue>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;

    Node(int value) 
    {
        data = value;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int key) 
{
    if (root == nullptr) 
    {
        return new Node(key);
    }
    if (key < root->data) 
    {
        root->left = insert(root->left, key);
    } else 
    {
        root->right = insert(root->right, key);
    }
    return root;
}

Node* findMin(Node* root) 
{
    while (root->left != nullptr) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) 
{
    if (root == nullptr) return root;
    if (key < root->data) 
    {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) 
    {
        root->right = deleteNode(root->right, key);
    } else 
    {
        if (root->left == nullptr) 
        {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) 
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) 
{
    if (root != nullptr) 
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

bool search(Node* root, int key) {
    if (root == nullptr) return false;
    if (root->data == key) return true;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

void bfs(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();
        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "In-order traversal: ";
    inorder(root);
    cout << endl;

    cout << "BFS traversal: ";
    bfs(root);
    cout << endl;

    cout << "Searching for 40: " << (search(root, 40) ? "Found" : "Not Found") << endl;

    cout << "Deleting 20\n";
    root = deleteNode(root, 20);
    cout << "In-order traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
