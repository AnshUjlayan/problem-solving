class Solution {
public:
    int jump(vector<int>& arr) {
        int n = arr.size();
        int aukat = 0;
        int potentialAukat = arr[0];
        int phoneCall = 0;
        for (int i = 0; i < n; i++) {
            if (aukat < i) {
                phoneCall++;
                aukat = potentialAukat;
            }
            potentialAukat = max(potentialAukat, i + arr[i]);
        }
        return phoneCall;
    }
};