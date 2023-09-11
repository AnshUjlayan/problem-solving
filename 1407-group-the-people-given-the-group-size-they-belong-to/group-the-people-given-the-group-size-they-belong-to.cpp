class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int idx = 0, n = groupSizes.size();
        vector<vector<int>> result;
        vector<pair<int,int>> groups;
        for(int i = 0; i < n; i++) {
            groups.push_back({groupSizes[i], i});
        }
        sort(groups.begin(), groups.end());
        while(idx < n) {
            vector<int> currGroup;
            int groupEnd = idx + groups[idx].first;
            while(idx < groupEnd) {
                currGroup.push_back(groups[idx++].second);
            }
            result.push_back(currGroup);
        }
        return result;
    }
};