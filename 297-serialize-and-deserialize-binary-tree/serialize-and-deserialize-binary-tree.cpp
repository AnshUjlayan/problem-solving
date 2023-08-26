/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        if(!root) {
            return str;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if(!front) {
                str += "n|";
                continue;
            }
            q.push(front->left);
            q.push(front->right);
            str += to_string(front->val) + "|";
        }
        return str;
    }

    // Decodes your encoded data to tree.

    TreeNode* getNode(string& data, int& idx) {
        string s = "";
        while(idx < data.size() && data[idx] != '|') {
            s += data[idx++];
        }
        idx++;
        if(s == "n" || s == "") {
            return nullptr;
        }
        return new TreeNode(stoi(s));
    }

    TreeNode* deserialize(string data) {
        if(!data.size()) {
            return nullptr;
        }
        queue<TreeNode*> q;
        int idx = 0;
        TreeNode* root = getNode(data, idx);
        q.push(root);
        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            front->left = getNode(data, idx);
            front->right = getNode(data, idx);
            if(front->left) {
                q.push(front->left);
            }
            if(front->right) {
                q.push(front->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));