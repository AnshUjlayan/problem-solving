class Solution {
public:
    void increment(string& result) {
        for (int i = result.size() - 1; i >= 0; --i) {
            if (result[i] == '0') {
                result[i] = '1';
                break;
            }
            result[i] = '0';
        }
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result(n, '0');
        sort(nums.begin(), nums.end());
        for (const string& num : nums) {
            if (num != result) {
                return result;
            }
            increment(result);
        }
        return result;
    }
};