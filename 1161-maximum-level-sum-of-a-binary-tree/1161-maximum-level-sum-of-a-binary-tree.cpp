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
    void inOrder(TreeNode* root, unordered_map<int,int>& ump, int level) {
        if(!root)
            return;
        inOrder(root->left, ump, level + 1);
        ump[level] += root->val;
        inOrder(root->right, ump, level + 1);
    }
public:
    int maxLevelSum(TreeNode* root) {
        unordered_map<int,int> ump;
        inOrder(root, ump, 1);
        int result = INT_MAX, val = INT_MIN;
        for(auto pair : ump) {
            if(pair.second > val) {
                result = pair.first;
                val = pair.second;
            }
            else if(pair.second == val) {
                result = min(result, pair.first);
            }
        }
        return result;
    }
};