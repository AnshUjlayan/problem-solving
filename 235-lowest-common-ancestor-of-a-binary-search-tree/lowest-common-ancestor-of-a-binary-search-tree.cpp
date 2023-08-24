/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    pair<TreeNode*,int> result = {nullptr, INT_MIN};
    pair<bool,bool> func(int depth, TreeNode* root, TreeNode* p, TreeNode* q) {
        pair<bool,bool> check;
        if(!root) {
            return check;
        }
        pair<bool,bool> l = func(depth + 1, root->left, p, q);
        pair<bool,bool> r = func(depth + 1, root->right, p, q);
        check.first = (root->val == p->val) || l.first || r.first;
        check.second = (root->val == q->val) || l.second || r.second;
        if(check.first && check.second && result.second < depth) {
            result = {root, depth};
        }
        return check;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        func(0, root, p, q);
        return result.first;
    }
};