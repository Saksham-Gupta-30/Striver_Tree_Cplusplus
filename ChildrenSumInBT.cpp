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

void traverse(Node *root);
vector<vector<int>> levelOrder(Node *root);
void childrenSum(Node *root);

int main() {
    struct Node *root = new Node(40);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->right = new Node(5);
    root->left->left = new Node(2);
    root->right->right = new Node(40);
    root->right->left = new Node(30);

    traverse(root);
    childrenSum(root);
    cout << "\nAfter Children Sum\n";
    traverse(root);

    return 0;
}

void traverse(Node *root) {
    vector<vector<int>> ans;
    ans = levelOrder(root);
    for (auto i: ans) {
        for (auto j: i)
            cout << j << " ";
        cout << endl;
    }
}

vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> ans;
    if (root == NULL) return ans;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++) {
            Node *node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

// CHILDREN_SUM_IN_BT (MAIN FUNCTION)
void childrenSum(Node *root) {
    if (!root) return;
    int child = 0;
    if (root->left) {
        child += root->left->data;
    }
    if (root->right) {
        child += root->right->data;
    }
    if (child >= root->data) root->data = child;
    else {
        if (root->left) root->left->data = root->data;
        else if (root->right) root->right->data = root->data;
    }

    childrenSum(root->left);
    childrenSum(root->right);

    int back_track = 0;
    if (root->left) back_track += root->left->data;
    if (root->right) back_track += root->right->data;
    if (root->left or root->right) root->data = back_track;
}
