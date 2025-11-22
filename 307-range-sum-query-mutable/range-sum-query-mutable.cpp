class NumArray {
public:
    vector<int> nums, fen;

    NumArray(vector<int>& nums) {
        this->nums = nums;
        fen.assign(nums.size() + 1, 0);
        copy(nums.begin(), nums.end(), fen.begin() + 1);
        for (int i = 1; i < fen.size(); i++) {
            int parent = i + (i & -i);
            if (parent < fen.size()) {
                fen[parent] += fen[i];
            }
        }
    }

    int sum(int i) {
        int res = 0;
        while (i > 0) {
            res += fen[i];
            i -= i & -i;
        }
        return res;
    }
        
    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index++] = val;
        while (index < fen.size()) {
            fen[index] += delta;
            index += index & -index;
        }
    }

    int sumRange(int left, int right) {
        return sum(right + 1) - sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */