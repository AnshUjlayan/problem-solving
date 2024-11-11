class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> primes;
        for (int i = 2; i <= 1000; i++) {
            int x = i;
            bool flg = true;
            for (int j = 2; j * j <= i; j++) {
                if (x % j == 0) {
                    flg = false;
                    break;
                }
            }
            if (flg) {
                primes.push_back(i);
            }
        }
        int n = nums.size(), m = primes.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] >= nums[i + 1]) {
                int temp = nums[i] - nums[i + 1] + 1;
                int idx = lower_bound(primes.begin(), primes.end(), temp) - primes.begin();
                if (idx >= m || primes[idx] >= nums[i]) {
                    return false;
                }
                nums[i] -= primes[idx];
            }
        }
        return true;
    }
};