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
    void func(vector<string>& result, string& ans, TreeNode* root) {
        if(!root->left && !root->right) {
            result.push_back(ans);
            return;
        }
        if(root->left) {
            string temp = to_string(root->left->val);
            ans += "->" + temp;
            func(result, ans, root->left);
            for(int i = 0; i < temp.size() + 2; i++) {
                ans.pop_back();
            }
        }
        if(root->right) {
            string temp = to_string(root->right->val);
            ans += "->" + temp;
            func(result, ans, root->right);
            for(int i = 0; i < temp.size() + 2; i++) {
                ans.pop_back();
            }
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string ans = "";
        ans += to_string(root->val);
        func(result, ans, root);
        return result;
    }
};