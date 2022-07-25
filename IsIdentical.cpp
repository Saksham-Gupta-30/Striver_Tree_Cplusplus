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

bool IsSameTree(Node *root1, Node *root2);

int main () {
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(5);

    cout << "Tree 1 identical to Tree 2: " << boolalpha << IsSameTree(root1, root2) << endl;
    return 0;
}

bool IsSameTree(Node* root1, Node* root2) {
    if (root1 == NULL || root2 == NULL) return (root1 == root2);
    return (root1->data == root2->data)
            && IsSameTree(root1->left, root2->left)
            && IsSameTree(root1->right, root2->right);
}