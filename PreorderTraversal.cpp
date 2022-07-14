#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    Node (int value) {
        data = value;
        left = right = NULL;
    }
};

void PreorderTraversal(Node *root);

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left = new Node(7);

    PreorderTraversal(root);
    
    return 0;
}

void PreorderTraversal(Node *root) {
    if (root == NULL) return;
    cout << root->data << endl;
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}