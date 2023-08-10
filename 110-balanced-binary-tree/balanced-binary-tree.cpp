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
    bool isBalanced(TreeNode* root) {
        //recursively go up
        if (root == nullptr) {
            return true;
        }

        int height = 0;

        return dfs(root, height);
    } 

    bool dfs(TreeNode* root, int& height) {
        if (root == nullptr) {
            height = 0;
            return true;
        }

        int left = 0;
        int right = 0;

        if (!dfs(root->left, left) || !dfs(root->right, right)) {
            return false;
        }

        if (abs(left - right) > 1) {
            return false;
        }

        height = 1 + max(left, right);
        return true;
    }
};