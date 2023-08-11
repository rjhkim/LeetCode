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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p != nullptr && q == nullptr) {
            return false;
        }
        if (p == nullptr && q != nullptr) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        bool check = true;
        dfs(p, q, check);

        return check;
    }

    void dfs(TreeNode* p, TreeNode* q, bool& check) {
        if (p == nullptr && q != nullptr) {
            check = false;
            return;
        }
        if (p != nullptr && q == nullptr) {
            check = false;
            return;
        }
        if (p == nullptr && q == nullptr) {
            return;
        }
        if (p->val != q->val) {
            check = false;
        }
        dfs(p->left, q->left, check);
        dfs(p->right, q->right, check);
    }
};