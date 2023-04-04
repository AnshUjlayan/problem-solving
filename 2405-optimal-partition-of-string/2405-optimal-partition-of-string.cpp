class Solution {
public:
    int partitionString(string s) {
        int result = 1; 
        unordered_set<char> st;
        for(char c : s) {
            if(st.find(c) == st.end()) {
                st.insert(c);
            }
            else {
                result++;
                st.clear();
                st.insert(c);
            }
        }
        return result;
    }
};