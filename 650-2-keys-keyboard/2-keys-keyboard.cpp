class Solution {
public:
    int minSteps(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int factor = 2, result = 0;
        while (n > 1) {
            if (n % factor == 0) {
                n /= factor;
                result += factor;
            } else {
                factor++;
            }
        }
        return result;
    }
};