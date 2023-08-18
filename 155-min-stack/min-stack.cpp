class MinStack {
private:
    vector<pair<int,int>> stk;
    int minElement;
public:
    MinStack() {
        stk.clear();
        minElement = INT_MAX;
    }
    
    void push(int val) {
        minElement = min(minElement, val);
        stk.push_back({val, minElement});
    }
    
    void pop() {
        stk.resize(stk.size() - 1);
        if(!stk.empty()) {
            minElement = stk[stk.size() - 1].second;
        }
        else {
            minElement = INT_MAX;
        }
    }
    
    int top() {
        return stk[stk.size() - 1].first;
    }
    
    int getMin() {
        return minElement;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */