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
    TreeNode* func(vector<int>& preorder, vector<int>& inorder, int& idx, int l, int r) {
        if(l > r) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[idx]);
        int partition = 0;
        while(partition < inorder.size()) {
            if(inorder[partition] == preorder[idx]) {
                break;
            }
            partition++;
        }
        idx++;
        root->left = func(preorder, inorder, idx, l, partition - 1);
        root->right = func(preorder, inorder, idx, partition + 1, r);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        TreeNode* root = new TreeNode(0);
        int idx = 0;
        return func(preorder, inorder, idx, 0, n - 1);
    }
};