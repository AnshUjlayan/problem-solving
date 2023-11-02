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
    int result = 0;
    pair<int,int> getSlimy(TreeNode* root) {
        if(!root) {
            return {0, 0};
        }
        pair<int,int> left = getSlimy(root->left);
        pair<int,int> right = getSlimy(root->right);
        int childSum = root->val + left.first + right.first;
        int numNodes = 1 + left.second + right.second;
        int average = childSum / numNodes;
        this->result += average == root->val ? 1 : 0;
        return {childSum, numNodes};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        getSlimy(root);
        return result;
    }
};