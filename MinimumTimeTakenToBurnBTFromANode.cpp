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

int findMaxDistance(map<Node*, Node*>& mapParents, Node* target);
Node* bfsToMapParents(Node* root, map<Node*, Node*>& mapParents, int start);
int timeToBurnTree(Node* root, int start);

int main() {
    struct Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    // Time or Maximum Distance
    int time = timeToBurnTree(root, 2);
    cout << "Maximum Time To Burn Binary Tree From A Node: " << time << endl;

    return 0;
}

int findMaxDistance(map<Node*, Node*>& mapParents, Node* target) {
    queue<Node*> q;
    q.push(target);
    map<Node*, int> visited;
    visited[target] = 1;
    int maxDistance = 0;
    while (!q.empty()) {
        int size = q.size();
        int fl = 0;
        for (int i = 0; i < size; i++) {
            auto node = q.front();
            q.pop();
            if (node->left && !visited[node->left]) {
                fl = 1;
                visited[node->left] = 1;
                q.push(node->left);
            }
            if (node->right && !visited[node->right]) {
                fl = 1;
                visited[node->right] = 1;
                q.push(node->right);
            }
            if (mapParents[node] && !visited[mapParents[node]]) {
                fl = 1;
                visited[mapParents[node]] = 1;
                q.push(mapParents[node]);
            }
        }
        if (fl) maxDistance++;
    }
    return maxDistance;
}

Node* bfsToMapParents(Node* root, map<Node*, Node*>& mapParents, int start) {
    queue<Node*> q;
    q.push(root);
    Node* res;
    while (!q.empty()) {
        Node* node = q.front();
        if (node->data == start) res = node;
        q.pop();
        if (node->left) {
            mapParents[node->left] = node;
            q.push(node->left);
        }
        if (node->right) {
            mapParents[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}

int timeToBurnTree(Node* root, int start) {
    map<Node*, Node*> mapParents;
    Node* target = bfsToMapParents(root, mapParents, start);
    int maxDistance = findMaxDistance(mapParents, target);
    return maxDistance;
}