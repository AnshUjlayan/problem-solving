class LRUCache {
private:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {};
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    unordered_map<int,Node*> ump;
    int capacity = 0;

    void removeNode(Node* curr) {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->next = nullptr;
        curr->prev = nullptr;
        ump.erase(curr->key);
    }

    void insertNode(Node* curr) {
        head->next->prev = curr;
        curr->next = head->next;
        head->next = curr;
        curr->prev = head;
        ump[curr->key] = curr;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new Node(-1, -1);
        this->tail = new Node(-1, -1);
        this->head->next = tail;
        this->tail->prev = head;
        this->ump.clear();
    }
    
    int get(int key) {
        if(ump.find(key) == ump.end()) {
            return -1;
        }
        Node* curr = ump[key];
        removeNode(curr);
        insertNode(curr);
        return curr->val;
    }
    
    void put(int key, int value) {
        if(ump.find(key) != ump.end()) {
            removeNode(ump[key]);
        }
        else if(ump.size() == capacity) {
            removeNode(tail->prev);
        }
        Node* curr = new Node(key, value);
        insertNode(curr);
        ump[key] = curr;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */