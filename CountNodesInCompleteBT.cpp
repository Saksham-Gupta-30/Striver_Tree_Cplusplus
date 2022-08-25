#include<bits/stdc++.h>
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

int countNodes(Node*);
int leftHeight(Node*);
int rightHeight(Node*);

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);

    int nodeCount = countNodes(root);
    cout << "Count Of Nodes In Complete Binary Tree: " << nodeCount << endl;

    return 0;
}

int countNodes(Node *root) {
    if (root == NULL) return 0;

    int lh = leftHeight(root);
    int rh = rightHeight(root);

    if (lh == rh) return (1 << lh) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int leftHeight(Node *node) {
    int height = 0;
    while (node) {
        height++;
        node = node->left;
    }
    return height;
}

int rightHeight(Node *node) {
    int height = 0;
    while (node) {
        height++;
        node = node->right;
    }
    return height;
}