class Solution {
public:
    int numberOfWays(string corridor) {
        long long result = 1, mod = 1e9 + 7;
        int n = corridor.size(), i = -1;
        vector<pair<int,int>> ranges;
        while(++i < n) {
            if(corridor[i] == 'S') {
                int l = i;
                while(++i < n) {
                    if(corridor[i] == 'S') {
                        ranges.push_back({l, i});
                        break;
                    }
                }
                if(i == n) {
                    return 0;
                }
            }
        }
        for(int i = 1; i < ranges.size(); i++) {
            auto& [prevL, prevR] = ranges[i - 1];
            auto& [l, r] = ranges[i];
            result *= (l - prevR);
            result %= mod;
        }
        return ranges.size() ? (int)result : 0;
    }
};