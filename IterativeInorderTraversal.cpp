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

vector<int> IterativeInorderTraversal(Node *root);

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left = new Node(7);
    
    vector<int> inorder = IterativeInorderTraversal(root);
    for (auto it: inorder) cout << it << endl;

    return 0;
}

vector<int> IterativeInorderTraversal(Node *root) {
    vector<int> inorder;
    if (root == NULL) return inorder;
    stack<Node*> st;
    Node *node = root;
    while (true) {
        if (node != NULL) {
            st.push(node);
            node = node->left;
        }
        else {
            if (st.empty() == true) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    return inorder;
}