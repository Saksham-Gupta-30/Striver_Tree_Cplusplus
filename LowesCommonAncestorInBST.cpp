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

Node* LCAInBST(Node*, Node*, Node*);

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

    Node* node = LCAInBST(root, root->left->left, root->left->right);
    cout << "Lowest Common Ancestor: " << node->data << endl;
}

Node* LCAInBST(Node* root, Node* p, Node* q) {
    if (root == NULL) return NULL;
    int curr = root->data;
    if (curr > p->data && curr > q->data) return LCAInBST(root->left, p, q);
    if (curr < p->data && curr < q->data) return LCAInBST(root->right, p, q);
    return root;
}