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

string serialize(Node *node);
Node* deserialize(string str);

vector<vector<int>> LevelorderTraversal(Node *root);


int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left->right = new Node(6);

    string str = serialize(root);
    cout << "Serialized Binary Tree: " << str << endl;
    Node *node = deserialize(str);
    cout << "Deserialized String" << endl;
    vector<vector<int>> ans = LevelorderTraversal(node);
    cout << "LevelorderTraversal" << endl;
    for (auto it: ans) {
        for (auto i: it)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

string serialize(Node *root) {
    if (!root) return "";

    string s;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *currNode = q.front();
        q.pop();
        if (currNode == NULL) s.append("#,");
        else s.append(to_string(currNode->data) + ",");
        if (currNode) {
            q.push(currNode->left);
            q.push(currNode->right);
        }
    }
    return s;
}

Node* deserialize(string val) {
    if (val.size() == 0) return NULL;
    stringstream s(val);
    string str;
    getline(s, str, ',');
    Node *root = new Node(stoi(str));
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *node = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "#") {
            node->left = NULL;
        }
        else {
            Node *leftNode = new Node(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ',');
        if (str == "#") {
            node->right = NULL;
        }
        else {
            Node *rightNode = new Node(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
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