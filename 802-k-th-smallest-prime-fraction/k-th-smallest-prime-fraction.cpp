class Solution {
private:
    double frac(int a, int b) {
        return -static_cast<double>(a) / b;
    }

public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        priority_queue<pair<double,pair<int,int>>> pq;
        int n = arr.size();
        for(int i = 0; i < n - 1; i++) {
            pq.push({frac(arr[i], arr[n - 1]), {i, n - 1}});
        }
        while(--k) {
            auto [l, r] = pq.top().second;
            pq.pop();
            if(l < r) {
                pq.push({frac(arr[l], arr[r - 1]), {l, r - 1}});
            }
        }
        auto [l, r] = pq.top().second;
        return vector<int>({arr[l], arr[r]});
    }
};