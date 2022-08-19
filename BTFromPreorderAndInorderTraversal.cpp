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

Node *buildTree(vector<int>& preorder, vector<int>& inorder);
Node *buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMao);

vector<vector<int>> LevelorderTraversal(Node *root);

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    struct Node *node = buildTree(preorder, inorder);
    
    vector<vector<int>> ans = LevelorderTraversal(node);
    cout << "LevelorderTraversal" << endl;
    for (auto it: ans) {
        for (auto i: it)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

Node *buildTree(vector<int>& preorder, vector<int>& inorder) {
    map<int, int> inMap;

    for (int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;

    Node *root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);

    return root;
}

Node *buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap) {
    if (preStart > preEnd || inStart > inEnd) return NULL;

    Node *root = new Node(preorder[preStart]);

    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
    root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

    return root;
}

vector<vector<int>> LevelorderTraversal(Node *root) {
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