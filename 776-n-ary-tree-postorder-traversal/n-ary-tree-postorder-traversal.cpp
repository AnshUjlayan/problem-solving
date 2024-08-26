/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    vector<int> result;
    void getSlimy(Node* root) {
        if (!root)
            return;
        
        for (Node* child : root->children)
            getSlimy(child);
            
        result.push_back(root->val);
    }

public:
    vector<int> postorder(Node* root) {
        getSlimy(root);
        return result;
    }
};