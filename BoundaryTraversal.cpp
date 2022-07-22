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

vector<int> BoundaryTraversal(Node *root);
bool isLeaf(Node *root);
void addLeftBoundary(Node *root, vector<int> &ans);
void addLeaves(Node *root, vector<int> &ans);
void addRightBoundary(Node *root, vector<int> &ans);

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left = new Node(7);
    root->right->right->left = new Node(8);

    vector<int> ans = BoundaryTraversal(root);
    for (auto it: ans) cout << it << " ";
    
    return 0;
}

vector<int> BoundaryTraversal(Node *root) {
    vector<int> ans;
    if (root == NULL) return ans;
    if (!isLeaf(root)) ans.push_back(root->data);
    addLeftBoundary(root, ans);
    addLeaves(root, ans);
    addRightBoundary(root, ans);
    return ans;
}

bool isLeaf(Node *root) {
    if (root->left == NULL && root->right == NULL) return true;
    return false;
}

void addLeftBoundary(Node *root, vector<int> &ans) {
    Node *node = root->left;
    while (node) {
        if (!isLeaf(node)) ans.push_back(node->data);
        if (node->left) node = node->left;
        else node = node->right;
    }
}

void addLeaves(Node *root, vector<int> &ans) {
    if (isLeaf(root)) {
        ans.push_back(root->data);
        return;
    }
    if (root->left) addLeaves(root->left, ans);
    if (root->right) addLeaves(root->right, ans);
}

void addRightBoundary(Node *root, vector<int> &ans) {
    Node *node = root->right;
    vector<int> temp;
    while (node) {
        if (!isLeaf(node)) temp.push_back(node->data);
        if (node->right) node = node->right;
        else node = node->left;
    }
    for (auto it: temp) ans.push_back(it);
}