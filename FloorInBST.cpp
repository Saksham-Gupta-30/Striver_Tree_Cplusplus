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

int findFloor(Node*, int);

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

    int floor = findFloor(root, 5);
    if (floor == -1) cout << "NO FLOOR VALUE";
    else cout << floor << endl;

    return 0;
}

int findFloor(Node* root, int val) {
    int floor = -1;
    while (root) {
        if (root->data == val) {
            floor = root->data;
            return floor;
        }
        else if (val > root->data) {
            floor = root->data;
            root = root->right;
        }
        else
            root = root->left;
    }
    return floor;
}