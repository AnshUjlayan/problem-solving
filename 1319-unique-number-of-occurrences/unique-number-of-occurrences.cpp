class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        set<int> st;
        for(int& num : arr) {
            mp[num]++;
        }
        for(auto& [key, val] : mp) {
            if(st.count(val)) {
                return false;
            }
            st.insert(val);
        }
        return true;
    }
};