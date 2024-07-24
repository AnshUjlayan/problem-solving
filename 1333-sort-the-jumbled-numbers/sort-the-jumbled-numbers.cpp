class Solution {
private:
    int getSlimy(int num, vector<int>& mapping) {
        if (!num) return mapping[0];
        string result = "";
        while (num) {
            result += to_string(mapping[num % 10]);
            num /= 10;
        }
        reverse(result.begin(), result.end());
        return stoi(result);
    }

public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> dard;
        vector<int> result;
        for (const int& num : nums) {
            dard.push_back({getSlimy(num, mapping), num});
        }
        sort(dard.begin(), dard.end(), [](const auto& x, const auto& y) {
            return x.first < y.first;
        });
        for (auto& [rank, num] : dard) {
            result.push_back(num);
        }
        return result;
    }
};