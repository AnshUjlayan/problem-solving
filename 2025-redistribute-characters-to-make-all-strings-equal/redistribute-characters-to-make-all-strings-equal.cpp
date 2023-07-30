class Solution {
public:
    bool makeEqual(vector<string>& words) {
        if(words.size() == 1)
            return true;
        unordered_map<char,int> ump;
        int n = words.size();
        for(auto& word : words) {
            for(auto& c : word) {
                ump[c]++;
            }
        }
        for(auto& ch : ump) {
            if(ch.second % n != 0)
                return false;
        }
        return true;
    }
};