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

bool isNull(Node *root);
bool getPath(Node *root, vector<int> &ans, int target);

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    root->left->right = new Node(6);
    root->right->left = new Node(7);
    root->right->right->left = new Node(8);

    vector<int> ans;
    if (!isNull(root)) getPath(root, ans, 8);
    for (auto it: ans) cout << it << " ";

    return 0;
}

bool isNull(Node *root) {
    if (root == NULL) return true;
    return false;
}

bool getPath(Node *root, vector<int> &ans, int target) {
    if (!root) return false;

    ans.push_back(root->data);

    if (root->data == target) return true;

    if (getPath(root->left, ans, target) || (getPath(root->right, ans, target))) return true;

    ans.pop_back();
    return false;
}