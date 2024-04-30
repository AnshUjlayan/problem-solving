class Solution {
public:
    long long wonderfulSubstrings(string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        long long result = 0;
        int bitmask = 0;
        map<int,int> mp {{0, 1}};
        for(char& c : word) {
            int mask = 1 << (c - 'a');
            bitmask ^= mask;
            result += mp[bitmask]++;
            for(int i = 0; i < 10; i++) {
                int searchMask = bitmask ^ (1 << i);
                result += mp[searchMask];
            }
        }
        return result;
    }
};