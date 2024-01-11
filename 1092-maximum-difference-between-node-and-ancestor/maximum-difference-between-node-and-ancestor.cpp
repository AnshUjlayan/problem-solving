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
    int result = 0;
    pair<int,int> getSlimy(TreeNode* root) {
        if(!root) {
            return {1e9, -1e9};
        }
        auto [leftLow, leftHigh] = getSlimy(root->left);
        auto [rightLow, rightHigh] = getSlimy(root->right);
        pair<int,int> curr;
        curr.first = min({root->val, leftLow, rightLow});
        curr.second = max({root->val, leftHigh, rightHigh});
        result = max({result, abs(root->val - curr.first), abs(root->val - curr.second)});
        return curr;
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        getSlimy(root);
        return this->result;
    }
};