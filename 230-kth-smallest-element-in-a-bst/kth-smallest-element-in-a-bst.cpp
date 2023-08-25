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
    void func(TreeNode* root, int& result, int& k) {
        if(!root) {
            return;
        }
        func(root->left, result, k);
        if(k == 1) {
            result = root->val;
        }
        k--;
        func(root->right, result, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int result = INT_MAX;
        func(root, result, k);
        return result;
    }
};