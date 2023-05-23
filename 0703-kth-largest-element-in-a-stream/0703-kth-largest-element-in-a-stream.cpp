class KthLargest {
private:
    vector<int> vec;
    int x;
public:
    KthLargest(int k, vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vec = vector<int>(nums.begin(), nums.end());
        x = k;
    }
    int add(int val) {
        auto i = vec.begin();
        while (i != vec.end() && *i < val) {
            i++;
        }
        vec.insert(i, val);
        return *(vec.begin() + vec.size() - x);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */