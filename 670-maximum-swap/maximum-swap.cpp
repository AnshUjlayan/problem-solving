class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != '9') {
                int idx = i;
                char mx = '0';
                for (int j = i + 1; j < n; j++) {
                    if (s[j] >= mx) {
                        mx = s[j];
                        idx = j;
                    }
                }
                if (s[i] < s[idx]) {
                    swap(s[i], s[idx]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};