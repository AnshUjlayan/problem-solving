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
    int maxDepth = 0;
    void getSlimy(vector<int>& result, TreeNode* root, int depth) {
        if(!root) {
            return;
        }
        result[depth] = max(result[depth], root->val);
        maxDepth = max(maxDepth, depth + 1);
        getSlimy(result, root->left, depth + 1);
        getSlimy(result, root->right, depth + 1);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result(1e4, INT_MIN);
        getSlimy(result, root, 0);
        return vector<int>(result.begin(), result.begin() + maxDepth);
    }
};