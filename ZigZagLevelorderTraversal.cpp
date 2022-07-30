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

vector<vector<int>> ZigZagLevelorderTraversal(Node *root);

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left = new Node(7);
    root->right->right->left = new Node(8);

    vector<vector<int>> ans = ZigZagLevelorderTraversal(root);
    for (auto it: ans) {
        for (auto i: it)
            cout << i << " ";
        cout << endl;
    }
    
    return 0;
}

vector<vector<int>> ZigZagLevelorderTraversal(Node *root) {
    vector<vector<int>> ans;
    if (root == NULL) return ans;
    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);
        for (int i = 0; i < size; i++) {
            Node *node = q.front();
            q.pop();

            // find position to fill node's value
            int index = (leftToRight) ? i : (size - 1 - i);

            level[index] = node->data;
            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);

        }

        leftToRight = !leftToRight;
        ans.push_back(level);
    }
    return ans;
}