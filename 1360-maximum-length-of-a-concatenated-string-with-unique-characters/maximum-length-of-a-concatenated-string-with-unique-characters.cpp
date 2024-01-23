class Solution {
private:
    vector<map<int,int>> dp;
    int getMask(string& str) {
        int mask = 0;
        for(char& c : str) {
            int temp = 1;
            temp <<= (c - 'a');
            if(mask & temp) {
                return INT_MAX;
            }
            mask |= temp;
        }
        return mask;
    }

    int getSlimy(vector<string>& arr, int idx, int mask) {
        if (idx == arr.size()) {
            return 0;
        }
        if (dp[idx].find(mask) != dp[idx].end()) {
            return dp[idx][mask];
        }
        int currMask = getMask(arr[idx]);
        if (currMask == INT_MAX || (mask & currMask)) {
            return dp[idx][mask] = getSlimy(arr, idx + 1, mask);
        }
        int pick = arr[idx].size() + getSlimy(arr, idx + 1, mask | currMask);
        int skip = getSlimy(arr, idx + 1, mask);
        return dp[idx][mask] = max(pick, skip);
    }
    
public:
    int maxLength(vector<string>& arr) {
        this->dp.resize(arr.size());
        return getSlimy(arr, 0, 0);
    }
};