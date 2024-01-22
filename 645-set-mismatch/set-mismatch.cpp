class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result(2);
        set<int> st;
        for(int& num : nums) {
            if(st.count(num)) {
                result[0] = num;
            }
            st.insert(num);
        }
        for(int i = 1; i <= nums.size(); i++) {
            if(!st.count(i)) {
                result[1] = i;
                break;
            }
        }
        return result;
    }
};