#include<iostream>
#include<vector>
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
void inorder(Node* root, vector<int>& arr) {
    if (!root) return;

    inorder(root->left, arr);
    arr.push_back(root->key);
    inorder(root->right, arr);
}
vector<int> mergeArrays(vector<int>& a, vector<int>& b) {
    vector<int> res;
    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j])
            res.push_back(a[i++]);
        else
            res.push_back(b[j++]);
    }

    while (i < a.size()) res.push_back(a[i++]);
    while (j < b.size()) res.push_back(b[j++]);

    return res;
}
Node* buildBST(vector<int>& arr, int l, int r) {
    if (l > r) return NULL;

    int mid = l + (r - l) / 2;
    Node* root = new Node(arr[mid]);

    root->left = buildBST(arr, l, mid - 1);
    root->right = buildBST(arr, mid + 1, r);

    return root;
}
Node* mergeBST(Node* root1, Node* root2) {
    vector<int> a, b;

    inorder(root1, a);
    inorder(root2, b);

    vector<int> merged = mergeArrays(a, b);

    return buildBST(merged, 0, merged.size() - 1);
}