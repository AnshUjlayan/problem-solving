class Solution {
private:
    int getSlimy(vector<int>& rating) {
        int n = rating.size(), result = 0;
        vector<int> higher(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (rating[i] < rating[j]) {
                    higher[i]++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (rating[i] < rating[j]) {
                    result += higher[j];
                }
            }
        }

        return result;
    }

public:
    int numTeams(vector<int>& rating) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int result = getSlimy(rating);
        reverse(rating.begin(), rating.end());
        return result + getSlimy(rating);
    }
};