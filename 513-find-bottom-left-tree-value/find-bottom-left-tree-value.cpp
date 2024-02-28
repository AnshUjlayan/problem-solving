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
    int result = 0, maxDepth = 0;
    int findBottomLeftValue(TreeNode* root, int depth = 1) {
        if(!root) {
            return result;
        }
        if(depth > maxDepth) {
            result = root->val;
            maxDepth = depth;
        }
        findBottomLeftValue(root->left, depth + 1);
        findBottomLeftValue(root->right, depth + 1);
        return result;
    }
};