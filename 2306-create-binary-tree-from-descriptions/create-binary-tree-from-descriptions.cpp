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
    unordered_map<int,TreeNode*> ump;
    TreeNode* getNode(int n) {
        if (ump.count(n)) {
            return ump[n];
        }
        return ump[n] = new TreeNode(n);
    }
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_map<int,int> degree;
        for (auto& desc : descriptions) {
            degree[desc[0]] = degree[desc[0]];
            degree[desc[1]]++;
            if (desc[2]) {
                getNode(desc[0])->left = getNode(desc[1]);
            }
            else {
                getNode(desc[0])->right = getNode(desc[1]);
            }
        }
        for (auto& [key, val] : degree) {
            if (!val) {
                return getNode(key);
            }
        }
        return nullptr;
    }
};