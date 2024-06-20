class Solution {
private:
    int slimy(vector<int>& position, int m, int x) {
        int prev = -1e9;
        for(int& p : position) {
            if (p - prev >= x) {
                prev = p;
                m--;
            }
        }
        return m <= 0;
    }

public:
    int maxDistance(vector<int>& position, int m) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(position.begin(), position.end());
        int l = 0, r = 1e9;
        while(l <= r) {
            int mid = r - (r - l) / 2;
            if(slimy(position, m, mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l - 1;
    }
};