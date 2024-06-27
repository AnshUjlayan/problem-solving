class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_set<int> st;
        for (auto& edge : edges) {
            if(st.count(edge[0])) 
                return edge[0];
            if(st.count(edge[1])) 
                return edge[1];
            st.insert(edge[0]);
            st.insert(edge[1]);
        }
        return -1;
    }
};