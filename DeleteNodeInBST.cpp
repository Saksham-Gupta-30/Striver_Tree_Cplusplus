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

Node* deleteNode(Node*, int);
Node* helper(Node*);
Node* findLastRight(Node*);
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

    cout << "BEFORE DELETION" << endl;
    vector<vector<int>> ans = levelorder(root);
    for (auto i: ans) {
        for (auto j: i)
            cout << j << " ";
        cout << endl;
    }

    Node* node = deleteNode(root, 5);

    cout << "AFTER DELETION" << endl;
    ans = levelorder(node);
    for (auto i: ans) {
        for (auto j: i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}

Node* deleteNode(Node* root, int val) {
    if (root == NULL) return NULL;
    if (root->data == val) return helper(root);
    Node* dummy = root;
    while (root != NULL) {
        if (root->data > val) {
            if (root->left != NULL && root->left->data == val) {
                root->left = helper(root->left);
                break;
            }
            else root = root->left;
        }
        else {
            if (root->right != NULL && root->right->data == val) {
                root->right = helper(root->right);
                break;
            }
            else root = root->right;
        }
    }
    return dummy;
}

Node* helper(Node* root) {
    if (root->left == NULL) return root->right;
    if (root->right == NULL) return root->left;
    Node* rightChild = root->right;
    Node* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

Node* findLastRight(Node* root) {
    if (root->right == NULL) return root;
    return findLastRight(root->right);
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