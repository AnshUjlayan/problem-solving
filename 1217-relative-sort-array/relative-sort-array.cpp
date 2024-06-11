class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        map<int,int> mp;
        for(int& x : arr1) 
            mp[x]++;
        for(int& x : arr2)
            while(mp[x]--)
                result.push_back(x);
        for(auto& [key, val] : mp)
            while(val-- > 0)
                result.push_back(key);
        return result;
    }
};