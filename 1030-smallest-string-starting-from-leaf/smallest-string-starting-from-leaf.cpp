/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    string result = "~";
    void dard(TreeNode* root, string pain) {
        if (!root) return;
        pain.push_back(char(root->val + 97));
        if(!root->left && !root->right) {
            reverse(pain.begin(), pain.end());
            result = min(result, pain);
            return;
        }
        dard(root->left, pain);
        dard(root->right, pain);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        dard(root, "");
        return result;
    }
};