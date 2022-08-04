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

bool isNull(Node *root);
bool getPath(Node *root, vector<int> &ans, int target);
Node* LowestCommonAncestor(Node *root, Node *p, Node *q);

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    root->left->right = new Node(6);
    root->right->left = new Node(7);
    root->right->right->left = new Node(8);

    int ans;

    //<---- Approach 1 ---->
    // vector<int> path1;
    // vector<int> path2;
    // if (!isNull(root)) {
    //     getPath(root, path1, 8);
    //     getPath(root, path2, 7);
    // }

    // for (int i = 0; i < min(path1.size(), path2.size()); i++) {
    //     if (path1[i] == path2[i]) ans = path1[i];
    // }


    //<---- Approach 2 ---->

    Node *node = LowestCommonAncestor(root, root->right->left, root->right->right->left);
    ans = node->data;
    cout << "Lowest Common Ancestor: " << ans << endl;
    return 0;
}

//<---- Approach 1 ---->

// bool isNull(Node *root) {
//     if (root == NULL) return true;
//     return false;
// }

// bool getPath(Node *root, vector<int> &ans, int target) {
//     if (!root) return false;

//     ans.push_back(root->data);

//     if (root->data == target) return true;

//     if (getPath(root->left, ans, target) || (getPath(root->right, ans, target))) return true;

//     ans.pop_back();
//     return false;
// }


//<---- Approach 2 ---->

Node* LowestCommonAncestor(Node* root, Node *p, Node *q) {
    if (root == NULL || root == p || root == q) return root;

    Node *Left = LowestCommonAncestor(root->left, p, q);
    Node *Right = LowestCommonAncestor(root->right, p, q);

    if (Left == NULL) return Right;
    else if (Right == NULL) return Left;
    else return root;
}