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

int maximumWidth(Node *root);

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left = new Node(7);
    root->right->right->right = new Node(8);

    int maxWidth = maximumWidth(root);
    cout << "Maximum Width: " << maxWidth << endl;

    return 0;
}

int maximumWidth(Node *root) {
    if (!root) return 0;
    int ans = 0;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        int size = q.size();
        int min_index = q.front().second;
        int first, last;
        for (int i = 0; i < size; i++) {
            int cur_index = q.front().second - min_index;
            Node *node = q.front().first;
            q.pop();
            if (i == 0) first = cur_index;
            if (i == size - 1) last = cur_index;
            if (node->left)
                q.push({node->left, cur_index*2+1});
            if (node->right)
                q.push({node->right, cur_index*2+2});
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}