class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>> mp;
        for(int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(i);
        }
        vector<vector<string>> result;
        for(auto& [key, val] : mp) {
            vector<string> arr;
            for(int& idx : val) {
                arr.push_back(strs[idx]);
            }
            result.push_back(arr);
        }
        return result;
    }
};