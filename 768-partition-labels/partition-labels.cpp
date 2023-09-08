class Solution {
private:
    vector<vector<int>> getIntervals(string s) {
        vector<vector<int>> intervals;
        unordered_map<char,int> ump;
        for(int i = 0; i < s.size(); i++) {
            if(ump.find(s[i]) == ump.end()) {
                intervals.push_back({i, i});
                ump[s[i]] = intervals.size() - 1;
            }
            else {
                int idx = ump[s[i]];
                intervals[idx][1] = i;
            }
        }
        return intervals;
    }
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        vector<vector<int>> intervals = getIntervals(s);
        int l = intervals[0][0], r = intervals[0][1];
        for(auto& interval : intervals) {
            if(interval[0] > r) {
                result.push_back(r - l + 1);
                l = interval[0];
            }
            r = max(interval[1], r);
        }
        result.push_back(r - l + 1);
        return result;
    }
};