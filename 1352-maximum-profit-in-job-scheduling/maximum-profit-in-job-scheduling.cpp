class Solution {
private:
    vector<int> dp;
    struct Jobs {
        int start, end, profit;
        Jobs(int start, int end, int profit) : start(start), end(end), profit(profit) {}
        bool operator<(const Jobs& other) const {
            return start < other.start;
        }
    };
    int getSlimy(vector<Jobs>& jobs, int idx) {
        if(idx == jobs.size()) {
            return 0;
        }
        if(dp[idx] != -1) {
            return dp[idx];
        }
        auto& [start, end, profit] = jobs[idx];
        int nextIdx = lower_bound(jobs.begin() + idx + 1, jobs.end(), end, 
            [](const Jobs& a, int value) {
                return a.start < value;
            })
        - jobs.begin();
        return dp[idx] = max(
            getSlimy(jobs, idx + 1), 
            profit + getSlimy(jobs, nextIdx)
        );
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Jobs> jobs;
        for(int i = 0; i < startTime.size(); i++) {
            jobs.push_back(Jobs(startTime[i], endTime[i], profit[i]));
        }
        sort(jobs.begin(), jobs.end());
        this->dp.resize(jobs.size(), -1);
        return getSlimy(jobs, 0);
    }
};