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

int MaximumPathSum(Node *root, int &maxi);

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left = new Node(7);
    root->right->right->left = new Node(8);
    
    int maxi = INT_MIN;
    MaximumPathSum(root, maxi);
    cout << "Maximum Path Sum: " << maxi << endl;

    return 0;
}

int MaximumPathSum(Node *root, int &maxi) {
    if (root == NULL) return 0;
    int left = max(0, MaximumPathSum(root->left, maxi));
    int right = max(0, MaximumPathSum(root->right, maxi));
    maxi = max(maxi, left + right + root->data);

    return max(left, right) + root->data;
}