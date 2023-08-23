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
    bool result = true;
    int check(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int l = check(root->left);
        int r = check(root->right);
        result &= (abs(l - r) <= 1);
        return 1 + max(l, r);
    }
public:
    bool isBalanced(TreeNode* root) {
        check(root);
        return result;
    }
};