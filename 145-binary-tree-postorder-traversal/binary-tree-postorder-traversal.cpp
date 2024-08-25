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
private:
    vector<int> result;
    void getSlimy(TreeNode* root) {
        if (!root) {
            return;
        }
        getSlimy(root->left);
        getSlimy(root->right);
        result.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        getSlimy(root);
        return result;
    }
};