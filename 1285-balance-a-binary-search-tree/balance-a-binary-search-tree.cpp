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
    void dfs(TreeNode* root, vector<int>& nums) {
        if (!root)
            return;
        dfs(root->left, nums);
        nums.push_back(root->val);
        dfs(root->right, nums);
    }
    TreeNode* tree(vector<int>& nums, int l, int r) {
        if(l > r)
            return nullptr;
        int mid = l + (r - l) / 2;
        return new TreeNode(nums[mid], tree(nums, l, mid - 1), tree(nums, mid + 1, r));
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> nums;
        dfs(root, nums);
        return tree(nums, 0, nums.size() - 1);
    }
};