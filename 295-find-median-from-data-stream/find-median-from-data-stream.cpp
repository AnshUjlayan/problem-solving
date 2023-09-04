class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int length;
public:
    MedianFinder() {
        this->maxHeap = priority_queue<int>();
        this->minHeap = priority_queue<int, vector<int>, greater<int>>();
        this->length = 0;
    }
    
    void addNum(int num) {
        length++;
        if(length == 1) {
            maxHeap.push(num);
            minHeap.push(num);
            return;
        }
        if(num < minHeap.top()) {
            maxHeap.push(num);
            if(length & 1) {
                minHeap.push(maxHeap.top());
            }
            else {
                maxHeap.pop();
            }
        }
        else {
            minHeap.push(num);
            if(length & 1) {
                maxHeap.push(minHeap.top());
            }
            else {
                minHeap.pop();
            }
        }
    }
    
    double findMedian() {
        if(length & 1) {
            return (double)minHeap.top();
        }
        return (double)(minHeap.top() + maxHeap.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */