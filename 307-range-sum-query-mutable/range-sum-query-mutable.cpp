class NumArray {
private:
    int n;
    vector<int> nums, segment;

    int segmentTree(int idx, int l, int r) {
        if(l == r) {
            return segment[idx] = nums[l];
        }
        int mid = l + (r - l) / 2;
        int left = segmentTree(idx * 2 + 1, l, mid);
        int right = segmentTree(idx * 2 + 2, mid + 1, r);
        return segment[idx] = left + right;
    }

    int updateSegment(int idx, int l, int r, int update) {
        if(l > update || r < update) {
            return segment[idx];
        }
        else if(l == r) {
            return segment[idx] = nums[update];
        }
        int mid = l + (r - l) / 2;
        int leftArr = updateSegment(idx * 2 + 1, l, mid, update);
        int rightArr = updateSegment(idx * 2 + 2, mid + 1, r, update);
        return segment[idx] = leftArr + rightArr;
    }

    int segmentSum(int idx, int l, int r, int left, int right) {
        if(l >= left && r <= right) {
            return segment[idx];
        }
        else if(l > right || r < left) {
            return 0;
        }
        int mid = l + (r - l) / 2;
        int leftArr = segmentSum(idx * 2 + 1, l, mid, left, right);
        int rightArr = segmentSum(idx * 2 + 2, mid + 1, r, left, right);
        return leftArr + rightArr;
    }

public:
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        this->nums = nums;
        this->segment.resize(n * 4);
        segmentTree(0, 0, n - 1);
    }
    
    void update(int index, int val) {
        this->nums[index] = val;
        updateSegment(0, 0, n - 1, index);
    }
    
    int sumRange(int left, int right) {
        return segmentSum(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */