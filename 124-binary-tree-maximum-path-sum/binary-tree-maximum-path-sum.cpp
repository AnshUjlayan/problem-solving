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
    int func(TreeNode* root, int& result) {
        if(!root) {
            return 0;
        }
        int x = max(0, func(root->left, result));
        int y = max(0, func(root->right, result));
        result = max(result, root->val + x + y);
        return root->val + max(x, y);
    }
public:
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        func(root, result);
        return result;
    }
};