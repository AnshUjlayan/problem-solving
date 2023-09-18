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
    int result = 0;
    void zigZag(TreeNode* root, bool zig, int edges) {
        if(!root) {
            return;
        }
        result = max(result, edges);
        if(zig) {
            zigZag(root->left, false, edges + 1);
            zigZag(root->right, true, 1);
        }
        else {
            zigZag(root->left, false, 1);
            zigZag(root->right, true, edges + 1);
        }
    }
    int longestZigZag(TreeNode* root) {
        zigZag(root, true, 0);
        zigZag(root, false, 0);
        return result;
    }
};