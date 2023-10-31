class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size(), prev = 0;
        vector<int> result(n);
        for(int i = 0; i < n; i++) {
            int curr = prev ^ pref[i];
            result[i] = curr;
            prev ^= curr;
        }
        return result;
    }
};