class Solution {
public:
    int jump(vector<int>& arr) {
        int n = arr.size();
        vector<int> tab(n, 1e6);
        tab[n - 1] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j <= i + arr[i]; j++) {
                if (j < n)
                    tab[i] = min(tab[i], 1 + tab[j]);
            }
        }
        return tab[0];
    }
};