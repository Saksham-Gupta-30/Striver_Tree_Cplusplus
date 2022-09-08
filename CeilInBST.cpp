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

int findCeil(Node*, int);

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

    int ceil = findCeil(root, 115);
    if (ceil == -1) cout << "NO CEIL VALUE";
    else cout << ceil << endl;

    return 0;
}

int findCeil(Node* root, int val) {
    int ceil = -1;
    while (root) {
        if (root->data == val) {
            ceil = root->data;
            return ceil;
        }
        else if (root->data > val) {
            ceil = root->data;
            root = root->left;
        }
        else root = root->right;
    }
    return ceil;
}