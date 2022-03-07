/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSumUtil(TreeNode* root, int targetSum, vector<int> path) {
        if (!root) return 0;
        int count = 0;
        path.push(root->val);

        count += pathSumUtil(root->left, targetSum, path);
        count += pathSumUtil(root->right, targetSum, path);

        int sum = 0; 
        for (int i = path.size()-1; i >= 0; --i)
        {
            sum += path[i];
            if (sum == targetSum) count++;
        }
        path.pop();
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> paths;
        return pathSumUtil(root, targetSum, paths);
    }
};