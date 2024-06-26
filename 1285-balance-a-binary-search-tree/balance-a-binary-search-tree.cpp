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
    void dfs(TreeNode* root, vector<TreeNode*>& nums) {
        if (!root)
            return;
        dfs(root->left, nums);
        nums.push_back(root);
        dfs(root->right, nums);
    }
    TreeNode* tree(vector<TreeNode*>& nums, int l, int r) {
        if(l > r)
            return nullptr;
        int mid = l + (r - l) / 2;
        nums[mid]->left = tree(nums, l, mid - 1);
        nums[mid]->right = tree(nums, mid + 1, r);
        return nums[mid];
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<TreeNode*> nums;
        dfs(root, nums);
        return tree(nums, 0, nums.size() - 1);
    }
};