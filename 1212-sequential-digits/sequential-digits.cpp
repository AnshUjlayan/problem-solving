class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        set<int> result;
        double digits = 0.123456789;
        for(long long i = 10; i <= 1e9; i *= 10) {
            for(long long j = 10; j <= 1e9; j *= 10) {
                int num = int(digits * i) % j;
                if(num >= low && num <= high) {
                    result.insert(num);
                }
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};