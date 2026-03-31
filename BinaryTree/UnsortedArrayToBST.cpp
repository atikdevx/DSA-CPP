#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    int key;
    Node(int val)
    {
        data=val;
        left=right=nullptr;
    }
};
Node* insert(Node* root, int key) {
    if (root == NULL) {
        return new Node(key);
    }

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

Node* buildBSTFromUnsorted(vector<int>& arr) {
    Node* root = NULL;

    for (int x : arr) {
        root = insert(root, x);
    }

    return root;
}