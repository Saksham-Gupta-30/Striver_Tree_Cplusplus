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

vector<int> morrisInorder(Node*);

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);

    vector<int> inorder = morrisInorder(root);
    for (auto it: inorder) cout << it << " ";

    return 0;
}

vector<int> morrisInorder(Node* root) {
    vector<int> inorder;
    Node *curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else {
            Node *prev = curr->left;
            while (prev->right && prev->right != curr) {
                prev = prev->right;
            }

            if (prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            }
            else {
                prev->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inorder;
}