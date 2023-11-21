class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        long long result = 0;
        int mod = 1e9 + 7;
        unordered_map<int,int> ump;
        auto rev = [](int num)->int {
            string str = to_string(num);
            reverse(str.begin(), str.end());
            return stoi(str);
        };
        for(int& num : nums) {
            int temp = num - rev(num);
            ump[temp]++;
        }
        for(auto& [key, val] : ump) {
            int pairs = (1ll * val * (val - 1) / 2) % mod;
            result = (result + pairs) % mod;
        }
        return result;
    }
};