class Solution {
private:
    bool slimy(vector<int>& bloomDay, int m, int k, int t) {
        int streak = 0;
        for(int& day : bloomDay) {
            streak = day > t ? 0 : streak + 1;
            if(streak == k) {
                streak = 0;
                m--;
            }
        }
        return m <= 0;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int l = 0, r = 1e9;
        while(l <= r) {
            int mid = r - (r - l) / 2;
            if(slimy(bloomDay, m, k, mid)) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return l > 1e9 ? -1 : l;
    }
};