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
    int goodNodes(TreeNode* root, int currMax = INT_MIN) {
        if(!root) {
            return 0;
        }
        currMax = max(currMax, root->val);
        int curr = root->val >= currMax ? 1 : 0;
        return curr + goodNodes(root->left, currMax) + goodNodes(root->right, currMax);
    }
};