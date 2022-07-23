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

bool isSymmetric(Node *Left, Node *Right);

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->right->right = new Node(5);
    root->right->left = new Node(4);

    cout << boolalpha << ((root == NULL) || isSymmetric(root->left, root->right));

    return 0;
}

bool isSymmetric(Node *Left, Node *Right) {
    if (Left == NULL || Right == NULL) return (Left == Right);
    if (Left->data != Right->data) return false;
    return  isSymmetric(Left->left, Right->right)
            &&
            isSymmetric(Left->right, Right->left);
}