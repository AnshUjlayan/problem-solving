class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> ump;
        for (string& str : arr)
            ump[str]++;
        
        vector<string> vec;
        for (string& str : arr)
            if (ump[str] == 1)
                vec.push_back(str);
        
        return k <= vec.size() ? vec[k - 1] : "";
    }
};