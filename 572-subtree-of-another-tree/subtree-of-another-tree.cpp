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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) {
            return true;
        }
        if (root != nullptr && subRoot == nullptr) {
            return true;
        }
        if (root == nullptr && subRoot != nullptr) {
            return false;
        }

        bool check = true;
        int val = subRoot->val;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front->val == val) {
                same(front, subRoot, check);

                if (check == true) {
                    return true;
                }

                if (check == false) {
                    check = true;
                }
            }

            if (front->left != nullptr) {
            q.push(front->left);
             }
            if (front->right != nullptr) {
            q.push(front->right);
            }

        }

        return false; 
    }

    void same(TreeNode* p, TreeNode* q, bool& check) {
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
        same(p->left, q->left, check);
        same(p->right, q->right, check);
    }
};