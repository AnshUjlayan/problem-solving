class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size(), prev = 0;
        for(int i = 0; i < n; i++) {
            pref[i] = prev ^ pref[i];
            prev ^= pref[i];
        }
        return pref;
    }
};