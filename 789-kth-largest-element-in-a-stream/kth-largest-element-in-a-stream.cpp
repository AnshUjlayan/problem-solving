class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> heap;
    int heapSize;
public:
    KthLargest(int k, vector<int>& nums) {
        this->heap = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.end());
        this->heapSize = k;
    }
    
    int add(int val) {
        heap.push(val);
        while(heap.size() > heapSize) {
            heap.pop();
        }
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */