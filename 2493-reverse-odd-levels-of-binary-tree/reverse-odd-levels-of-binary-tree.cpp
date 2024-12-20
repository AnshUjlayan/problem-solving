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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<TreeNode*> row = {root}, nextRow;
        int level = 0;
        while (row[0]->left) {
            for (int i = 0; i < row.size(); i++) {
                nextRow.push_back(row[i]->left);
                nextRow.push_back(row[i]->right);
            }
            if (++level & 1) {
                for (int i = 0; i < nextRow.size() / 2; i++) {
                    swap(nextRow[i]->val, nextRow[nextRow.size() - i - 1]->val);
                }
            }
            row = nextRow;
            nextRow.clear();
        }
        return root;
    }
};