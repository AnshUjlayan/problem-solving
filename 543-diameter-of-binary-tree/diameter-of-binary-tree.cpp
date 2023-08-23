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
    int findMax(TreeNode* root, int& result) {
        if(!root) {
            return 0;
        }
        int l = findMax(root->left, result);
        int r = findMax(root->right, result);
        result = max(result, 1 + l + r);
        return 1 + max(l, r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        findMax(root, result);
        return result - 1;
    }
};