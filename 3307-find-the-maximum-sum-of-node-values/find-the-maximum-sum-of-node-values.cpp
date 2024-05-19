class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        long long result = 0;
        int count = 0;
        int minGain = 1e9, minLoss = 1e9;

        for(int& num : nums) {
            int XOR = num ^ k;
            if(XOR <= num) {
                result += num;
                minLoss = min(minLoss, num - XOR);
            }
            else {
                count++;
                result += XOR;
                minGain = min(minGain, XOR - num);
            }
        }

        if (count & 1) {
            result -= minGain < minLoss ? minGain : minLoss;
        }

        return result;
    }
};