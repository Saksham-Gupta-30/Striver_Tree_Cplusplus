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

vector<int> TopView(Node *root);

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left = new Node(7);
    root->right->right->right = new Node(8);

    vector<int> ans = TopView(root);
    for (auto it: ans) cout << it << " ";
    
    return 0;
}

vector<int> TopView(Node *root) {
    vector<int> ans;
    if (root == NULL) return ans;
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int line = it.second;
        if (mp.find(line) == mp.end()) mp[line] = node->data;
        if (node->left != NULL) q.push({node->left, line - 1});
        if (node->right != NULL) q.push({node->right, line + 1});
    }
    
    for (auto it: mp) ans.push_back(it.second);
    return ans;
}