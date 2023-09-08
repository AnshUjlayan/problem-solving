class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> result(3, false);
        for(auto& triplet : triplets) {
            if(triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) {
                result[0] = result[0] || (triplet[0] == target[0]);
                result[1] = result[1] || (triplet[1] == target[1]);
                result[2] = result[2] || (triplet[2] == target[2]);
            }
        }
        return result[0] && result[1] && result[2];
    }
};