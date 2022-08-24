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

void markparents(Node* root, unordered_map<Node*, Node*>& parent_track, Node* target);
vector<int> distanceK(Node* root, Node* target, int k);

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

    Node* target = root->left;

    vector<int> nodes;
    nodes = distanceK(root, target, 2);
    cout << "Nodes at a distance K\n";
    for (auto it: nodes) {
        cout << it << " ";
    }

    return 0;
}

void markparents(Node* root, unordered_map<Node*, Node*>& parent_track, Node* target) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty())  {
        Node *current = q.front();
        q.pop();
        if (current->left) {
            parent_track[current->left] = current;
            q.push(current->left);
        }
        if (current->right) {
            parent_track[current->right] = current;
            q.push(current->right);
        }
    }
}


// MAIN FUNCTION TO GET ALL THE NODES AT A DISTANCE K
vector<int> distanceK(Node* root, Node* target, int k) {
    unordered_map<Node*, Node*> parent_track;
    markparents(root, parent_track, target);

    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(target);
    visited[target] = true;
    int curr_level = 0;
    while (!q.empty()) {
        int size = q.size();
        if (curr_level++ == k) break;
        for (int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();
            if (current->left && !visited[current->left]) {
                q.push(current->left);
                visited[current->left] = true;
            }
            if (current->right && !visited[current->right]) {
                q.push(current->right);
                visited[current->right] = true;
            }
            if (parent_track[current] && !visited[parent_track[current]]) {
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }
    vector<int> ans;
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        ans.push_back(current->data);
    }
    return ans;
}