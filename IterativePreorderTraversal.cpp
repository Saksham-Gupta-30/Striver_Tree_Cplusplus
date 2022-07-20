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

vector<int> IterativePreorderTraversal(Node *root);

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left = new Node(7);
    
    vector<int> preorder = IterativePreorderTraversal(root);
    for (auto it: preorder) cout << it << endl;

    return 0;
}

vector<int> IterativePreorderTraversal(Node *root) {
    vector<int> preorder;
    if (root == NULL) return preorder;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        root = st.top();
        st.pop();
        preorder.push_back(root->data);
        if (root->right != NULL) st.push(root->right);
        if (root->left != NULL) st.push(root->left);
    }
    return preorder;
}