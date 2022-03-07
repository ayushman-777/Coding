//
// Created by patha on 29-10-2021.
//


#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *insert(TreeNode *root, int value) {
    if (root == nullptr) return new TreeNode(value);
    if (value < root->val) root->left = insert(root->left, value);
    else if (value > root->val) root->right = insert(root->right, value);
    else cout << endl << "Same value Node cannot be inserted.";
    return root;
}

TreeNode *search(TreeNode *root, int value) {
    if (root == nullptr) return nullptr;
    if (root->val == value) return root;
    else if (value < root->val) return search(root->left, value);
    else return search(root->right, value);
}

int maxInBST(TreeNode *root) {
    while (root->right) root = root->right;
    return root->val;
}

int minInBST(TreeNode *root) {
    while (root->left) root = root->left;
    return root->val;
}

TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr) return nullptr;
    else if (key < root->val) root->left = deleteNode(root->left, key);
    else if (key > root->val) root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        } else if (root->right && root->left) {
            int mx = minInBST(root->right);
            root->val = mx;
            root->right = deleteNode(root->right, mx);
        } else if (root->right) {
            TreeNode *temp = root;
            root = root->right;
            delete temp;
        } else {
            TreeNode *temp = root;
            root = root->left;
            delete temp;
        }
    }
    return root;
}

void levelOrder(TreeNode *root) {
    if (root == nullptr) return;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {
        TreeNode *temp = que.front();
        que.pop();
        cout << temp->val << "  ";
        if (temp->left) que.push(temp->left);
        if (temp->right) que.push(temp->right);
    }
}

TreeNode *constructTreeUtil(int pre[], int &preIndex, int key, int min, int max, int size) {
    if (preIndex >= size) return nullptr;
    TreeNode *temp = nullptr;
    if (min < key && max > key) {
        temp = new TreeNode(key);
        preIndex++;
        if (preIndex < size) temp->left = constructTreeUtil(pre, preIndex, pre[preIndex], min, key, size);
        if (preIndex < size) temp->right = constructTreeUtil(pre, preIndex, pre[preIndex], key, max, size);
    }
    return temp;
}

TreeNode *constructTree(int pre[], int size) {
    int preIndex = 0;
    return constructTreeUtil(pre, preIndex, pre[0], INT_MIN, INT_MAX, size);
}

void arrayToBSTUtil(vector<int> &nums, vector<int> &res, int start, int end) {
    if (start > end) {
        return;
    }
    int mid = (start + end) / 2;
    res.push_back(nums[mid]);
    arrayToBSTUtil(nums, res, start, mid - 1);
    arrayToBSTUtil(nums, res, mid + 1, end);
}

vector<int> sortedArrayToBST(vector<int> &nums) {
    vector<int> res;
    arrayToBSTUtil(nums, res, 0, nums.size() - 1);
    res.pop_back();
    return res;
}

int main() {
    TreeNode *root = new TreeNode(5);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 0);
    cout << endl;
    levelOrder(root);
    deleteNode(root, 5);
    cout << endl;
    levelOrder(root);
    return 0;
}