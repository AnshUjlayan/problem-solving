class MyCircularDeque {
private:
    struct Node {
        int val;
        Node *next, *prev;
        Node(int val, Node *prev, Node *next) {
            this->val = val;
            this->prev = prev;
            this->next = next;
        }
    };

    int k;
    Node *head, *tail;

    void insertNode(Node *newNode) {
        newNode->prev->next = newNode;
        newNode->next->prev = newNode;
        k--;
    }

    void deleteNode(Node *delNode) {
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
        k++;
    }

public:
    MyCircularDeque(int k) {
        this->k = k;
        this->head = new Node(-1, nullptr, tail);
        this->tail = new Node(-1, head, nullptr);
        head->next = tail;
        tail->prev = head;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        insertNode(new Node(value, head, head->next));
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        insertNode(new Node(value, tail->prev, tail));
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        deleteNode(head->next);
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        deleteNode(tail->prev);
        return true;
    }
    
    int getFront() {
        return head->next->val;
    }
    
    int getRear() {
        return tail->prev->val;
    }
    
    bool isEmpty() {
        return head->next->val < 0;
    }
    
    bool isFull() {
        return !k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */