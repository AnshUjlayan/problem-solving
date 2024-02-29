class Solution {
public:
    map<int,int> mp;
    bool isEvenOddTree(TreeNode* root, int level = 0) {
        if(!root) {
            return true;
        }
        mp[level] = mp[level] == 0 ? ((level & 1) ? 1e9 : 0) : mp[level];
        bool slime = level & 1 ? !(root->val & 1) && root->val < mp[level] : (root->val & 1) && root->val > mp[level];
        mp[level] = root->val;
        return slime && isEvenOddTree(root->left, level + 1) && isEvenOddTree(root->right, level + 1);
    }
};