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
    set<int> del;
    vector<TreeNode*> result;
    TreeNode* dfs(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        TreeNode* left = dfs(root->left);
        TreeNode* right = dfs(root->right);
        root->left = left;
        root->right = right;
        if (del.count(root->val)) {
            root = nullptr;
            if (left) {
                result.push_back(left);
            }
            if (right) {
                result.push_back(right);
            }
        }
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        del = set<int>(to_delete.begin(), to_delete.end());
        if (dfs(root)) {
            result.push_back(root);
        }
        return result;
    }
};