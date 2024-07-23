class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> result;
        map<int,int> mp;
        for (int& num : nums) {
            mp[num]++;
        }

        map<int, vector<int>> mp2;

        for (auto& [num, freq] : mp) {
            mp2[freq].push_back(num);
        }

        for (auto& [freq, arr] : mp2) {
            sort(arr.rbegin(), arr.rend());
            for (int j = 0; j < arr.size(); j++) {
                for (int k = 0; k < freq; k++) {
                    result.push_back(arr[j]);
                }
            }
        }
        return result;
    }
};