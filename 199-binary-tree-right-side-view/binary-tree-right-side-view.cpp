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
    void fillLevels(vector<int>& levels, TreeNode* root, int depth) {
        if(!root) {
            return;
        }
        if(levels[depth] == INT_MIN) {
            levels[depth] = root->val;
        }
        fillLevels(levels, root->right, depth + 1);
        fillLevels(levels, root->left, depth + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result, levels(101, INT_MIN);
        fillLevels(levels, root, 0);
        for(int i = 0; i <= 100; i++) {
            if(levels[i] == INT_MIN) {
                break;
            }
            result.push_back(levels[i]);
        }
        return result;
    }
};