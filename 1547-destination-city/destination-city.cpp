class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> result;
        for(auto& path : paths) {
            result[path[1]]++;
            if(--result[path[0]] == 0) {
                result.erase(path[0]);
            }
        }
        for(auto& path : paths) {
            if(--result[path[0]] <= 0) {
                result.erase(path[0]);
            }
        }
        return result.begin()->first;
    }
};