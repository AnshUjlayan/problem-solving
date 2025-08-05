class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int waterMinEnd = 1e9, landMinEnd = 1e9, res = 1e9;
        int n = landStartTime.size(), m = waterStartTime.size();
        for (int i = 0; i < n; i++) {
            landMinEnd = min(landMinEnd, landStartTime[i] + landDuration[i]);
        }
        for (int i = 0; i < m; i++) {
            waterMinEnd = min(waterMinEnd, waterStartTime[i] + waterDuration[i]);
        }
        for (int i = 0; i < n; i++) {
            res = min(res, max(waterMinEnd, landStartTime[i]) + landDuration[i]);
        }
        for (int i = 0; i < m; i++) {
            res = min(res, max(landMinEnd, waterStartTime[i]) + waterDuration[i]);
        }
        return res;
    }
};