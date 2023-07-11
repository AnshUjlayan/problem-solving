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
    void makeAdj(TreeNode* root, unordered_map<int, vector<int>>& adj, int parent) {
        if (!root)
            return;
        if (parent != -1)
            adj[root->val].push_back(parent);
        if (root->left) {
            adj[root->val].push_back(root->left->val);
            makeAdj(root->left, adj, root->val);
        }
        if (root->right) {
            adj[root->val].push_back(root->right->val);
            makeAdj(root->right, adj, root->val);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, bool> visited;
        makeAdj(root, adj, -1);
        vector<int> result;
        queue<pair<int, int>> q;
        q.push({target->val, 0});
        visited[target->val] = true;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int nodeVal = node.first;
            int distance = node.second;
            if (distance == k)
                result.push_back(nodeVal);
            else if (distance > k)
                break;
            for (int child : adj[nodeVal]) {
                if (!visited[child]) {
                    visited[child] = true;
                    q.push({child, distance + 1});
                }
            }
        }
        return result;
    }
};