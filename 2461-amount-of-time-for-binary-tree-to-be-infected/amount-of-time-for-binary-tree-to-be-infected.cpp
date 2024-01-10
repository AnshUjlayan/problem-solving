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
    int start, result = 0;
    pair<int,int> getSlimy(TreeNode* root) {
        if(!root) {
            return {0, -1e5};
        }
        auto [leftDepth, leftInfection] = getSlimy(root->left);
        auto [rightDepth, rightInfection] = getSlimy(root->right);
        int infectionDist = root->val == start ? 0 : max(leftInfection, rightInfection);
        if(leftInfection > 0) {
            result = max(result, leftInfection + rightDepth);
        }
        if(rightInfection > 0) {
            result = max(result, rightInfection + leftDepth);
        }
        if(infectionDist == 0) {
            result = max({result, leftDepth, rightDepth});
        }
        return {1 + max(leftDepth, rightDepth), 1 + infectionDist};
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        this->start = start;
        getSlimy(root);
        return this->result;
    }
};