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

int Diameter(Node *root, int &diameter);

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left = new Node(7);
    root->right->right->left = new Node(8);
    
    int diameter = -1;
    Diameter(root, diameter);
    cout << "Diameter: " << diameter << endl;

    return 0;
}

int Diameter(Node *root, int &diameter) {
    if (root == NULL) return 0;
    int lh = Diameter(root->left, diameter);
    int rh = Diameter(root->right, diameter);
    diameter = max(diameter, lh + rh);

    return 1 + max(lh, rh);
}