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
    int maxStreak = 0;
    int currStreak = 1;
    int currNum = 1e9;
    vector<int> result = {(int)1e9};
    void getSlimy(TreeNode* root) {
        if(!root) {
            return;
        }
        getSlimy(root->left);
        if(root->val == currNum) {
            currStreak++;
        }
        else {
            currStreak = 1;
            currNum = root->val;
        }
        if(currStreak > maxStreak) {
            this->result = {currNum};
            maxStreak = currStreak;
        }
        else if(currStreak == maxStreak) {
            this->result.push_back(currNum);
        }
        getSlimy(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        getSlimy(root);
        return result;
    }
};