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
    int count = 0;
    void getSlimy(TreeNode* root) {
        if(!root) {
            return;
        }
        getSlimy(root->right);
        count += root->val;
        root->val = count;
        getSlimy(root->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        getSlimy(root);
        return root;
    }
};