#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node (int value) {
        data = value;
        left = right = NULL;
    }
};

Node* insertNodeInBST(Node*, int);
vector<vector<int>> levelorder(Node*);

int main() {
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->left->right->left = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    cout << "BEFORE INSERTION" << endl;
    vector<vector<int>> ans = levelorder(root);
    for (auto i: ans) {
        for (auto j: i)
            cout << j << " ";
        cout << endl;
    }

    Node* node = insertNodeInBST(root, 11);

    cout << "AFTER INSERTION" << endl;
    ans = levelorder(node);
    for (auto i: ans) {
        for (auto j: i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}

Node* insertNodeInBST(Node* root, int val) {
    if (root == NULL) return new Node(val);
    Node* curr = root;
    while (true) {
        if (curr->data <= val) {
            if (curr->right != NULL) curr = curr->right;
            else { 
                curr->right = new Node(val);
                break;
            }
        }
        else {
            if (curr->left != NULL) curr = curr->left;
            else {
                curr->left = new Node(val);
                break;
            }
        }
    }
    return root;
}

vector<vector<int>> levelorder(Node *root) {
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
            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}