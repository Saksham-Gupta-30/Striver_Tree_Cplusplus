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

void LeftSideView(Node *root, int level, vector<int> &ans);

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left = new Node(7);
    root->right->right->right = new Node(8);

    vector<int> ans;
    LeftSideView(root, 0, ans);
    for (auto it: ans) cout << it << " " ;

    return 0;
}

void LeftSideView(Node *root, int level, vector<int> &ans) {
    if (root == NULL) return;
    if (ans.size() == level) ans.push_back(root->data);
    LeftSideView(root->left, level + 1, ans);
    LeftSideView(root->right, level + 1, ans);
}
