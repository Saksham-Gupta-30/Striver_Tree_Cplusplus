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

vector<int> IterativePostorderTraversal(Node *root);

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left = new Node(7);
    
    vector<int> postorder = IterativePostorderTraversal(root);
    for (auto it: postorder) cout << it << endl;

    return 0;
}

vector<int> IterativePostorderTraversal(Node *root) {
    vector<int> postorder;
    if (root == NULL) return postorder;
    stack<Node*> st;
    Node *node = root;
    while (node != NULL || !st.empty()) {
        if (node != NULL) {
            st.push(node);
            node = node->left;
        }
        else {
            Node *temp = st.top()->right;
            if (temp == NULL) {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else node = temp;
        }
    }
    return postorder;
}