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

Node *buildTree(vector<int>& postorder, vector<int>& inorder);
Node *buildTree(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMao);

vector<vector<int>> LevelorderTraversal(Node *root);

int main() {
    vector<int> postorder = {40, 50, 20, 60, 30, 10};
    vector<int> inorder = {40, 20, 50, 10, 60, 30};

    struct Node *node = buildTree(postorder, inorder);
    
    vector<vector<int>> ans = LevelorderTraversal(node);
    cout << "LevelorderTraversal" << endl;
    for (auto it: ans) {
        for (auto i: it)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

Node *buildTree(vector<int>& postorder, vector<int>& inorder) {
    map<int, int> inMap;

    for (int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;

    Node *root = buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);

    return root;
}

Node *buildTree(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap) {
    if (postStart > postEnd || inStart > inEnd) return NULL;

    Node *root = new Node(postorder[postEnd]);

    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTree(postorder, postStart, postStart + numsLeft - 1, inorder, inStart, inRoot - 1, inMap);
    root->right = buildTree(postorder, postStart + numsLeft, postEnd - 1, inorder, inRoot + 1, inEnd, inMap);

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