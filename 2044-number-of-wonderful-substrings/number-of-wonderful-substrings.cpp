class Solution {
public:
    long long wonderfulSubstrings(string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        long long result = 0;
        int bitmask = 0;
        unordered_map<int,int> mp {{0, 1}};
        for(char& c : word) {
            bitmask ^= 1 << (c - 'a');
            result += mp[bitmask]++;
            for(int i = 0; i < 10; i++) {
                result += mp[bitmask ^ (1 << i)];
            }
        }
        return result;
    }
};