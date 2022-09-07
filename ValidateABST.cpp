#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node (int value) {
        data = value;
        left = right = NULL;
    }
};

bool isValidBST(Node*);
bool isValidBST(Node*, int, int);

int main() {
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->left->right->left = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    bool ans = isValidBST(root);
    cout << boolalpha << ans << endl;

    return 0;
}

bool isValidBST(Node *root) {
    return isValidBST(root, INT_MIN, INT_MAX);
}

bool isValidBST(Node *root, int min, int max) {
    if (root == NULL) return true;
    if (root->data >= max || root->data <= min) return false;
    return isValidBST(root->left, min, root->data) && isValidBST(root->right, root->data, max);
}