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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int result = 0;
        dfs(root, result);

        return result;
    }

    int dfs(TreeNode* root, int& result) {
        if (root == nullptr) {
            return 0;
        }

        int l = dfs(root->left, result);
        int r = dfs(root->right, result);

        result = max(result, l + r);
        return 1 + max(l, r);
    }
};