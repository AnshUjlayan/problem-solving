class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int i = 0; i <= (int)arr.size() - 3; i++)
            if ((arr[i] & 1) && (arr[i + 1] & 1) && (arr[i + 2] & 1))
                return true;
        return false;
    }
};