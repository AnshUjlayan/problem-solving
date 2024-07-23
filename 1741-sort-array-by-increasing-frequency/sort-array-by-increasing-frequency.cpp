class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> result;
        map<int,int> mp;
        for (int& num : nums) {
            mp[num]++;
        }
        vector<pair<int,int>> dard;
        for (auto& [num, freq] : mp) {
            dard.push_back({freq, num});
        }
        sort(dard.begin(), dard.end(), [](const auto& x, const auto& y) {
            return x.first == y.first ? x.second > y.second : x.first < y.first;
        });
        for (auto& [freq, num] : dard) {
            while (freq--) {
                result.push_back(num);
            }
        }
        return result;
    }
};