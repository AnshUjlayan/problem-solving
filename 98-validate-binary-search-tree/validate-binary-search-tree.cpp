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
    bool isValidBST(TreeNode* root, long globalMin = LONG_MIN, long globalMax = LONG_MAX) {
        if(!root) {
            return true;
        }
        bool a = root->val > globalMin && root->val < globalMax;
        bool b = isValidBST(root->left, globalMin, root->val);
        bool c = isValidBST(root->right, root->val, globalMax);
        return a && b && c;
    }
};