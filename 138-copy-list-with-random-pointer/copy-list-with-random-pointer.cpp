/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    vector<int> getIdxList(Node* head) {
        Node* curr = head;
        unordered_map<Node*,int> ump;
        int idx = 0;
        while(curr) {
            ump[curr] = idx++;
            curr = curr->next;
        }
        curr = head;
        vector<int> idxList;
        while(curr) {
            if(curr->random == nullptr) {
                idxList.push_back(1e5);
            }
            else {
                idxList.push_back(ump[curr->random]);
            }
            curr = curr->next;
        }
        return idxList;
    }
public:
    Node* copyRandomList(Node* head) {
        vector<int> idxList = getIdxList(head);
        Node* curr = head;
        unordered_map<int,Node*> ump;
        int idx = 0;
        Node* newHead = new Node(0);
        Node* newCurr = newHead;
        while(curr) {
            newCurr->next = new Node(curr->val);
            newCurr = newCurr->next;
            ump[idx++] = newCurr;
            curr = curr->next;
        }
        newCurr = newHead->next;
        for(int i = 0; i < idxList.size(); i++) {
            Node* temp = ump[idxList[i]];
            if(idxList[i] == 1e5) {
                newCurr->random = nullptr;
            }
            else {
                newCurr->random = temp;
            }
            newCurr = newCurr->next;
        }
        return newHead->next;
    }
};