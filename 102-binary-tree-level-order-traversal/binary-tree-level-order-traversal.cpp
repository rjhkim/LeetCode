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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        bfs(q, ans);
        return ans;
    }

    void bfs(queue<TreeNode*> &q, vector<vector<int>> &ans) {
        while (!q.empty()) {
            int count = q.size();
            vector<int> temp;
            for (int i = 0; i < count; i++) {
                TreeNode* curr = q.front();
                temp.push_back(curr->val);
                q.pop();
                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }//for
            ans.push_back(temp);
        }
    }
};