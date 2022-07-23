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

int Check(Node *root);

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left = new Node(7);
    root->right->right->left = new Node(8);
    
    int isBalanced = Check(root);
    if (isBalanced == -1) cout << "Balanced Tree: False" << endl;
    else cout << "Balanced Tree: True" << endl;

    return 0;
}

int Check(Node *root) {
    if (root == NULL) return 0;
    int lh = Check(root->left);
    int rh = Check(root->right);
    if (lh == -1 || rh == -1) return -1;
    if (abs(lh - rh) > 1) return -1;
    return 1 + max(lh, rh);
}