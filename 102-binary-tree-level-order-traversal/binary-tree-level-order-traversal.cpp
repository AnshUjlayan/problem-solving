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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> curr;
        queue<pair<TreeNode*,int>> q;
        if(root) {
            q.push({root, 1});
        }
        int level = 0;
        while(!q.empty()) {
            pair<TreeNode*,int> front = q.front();
            q.pop();
            if(level < front.second) {
                level++;
                if(!curr.empty()) {
                    result.push_back(curr);
                    curr.clear();
                }
            }
            curr.push_back(front.first->val);
            if(front.first->left) {
                q.push({front.first->left, level + 1});
            }
            if(front.first->right) {
                q.push({front.first->right, level + 1});
            }
        }
        if(!curr.empty()) {
            result.push_back(curr);
        }
        return result;
    }
};