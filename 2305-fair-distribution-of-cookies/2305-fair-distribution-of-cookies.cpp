class Solution {
private:
    int func(vector<int>& cookies, int k, vector<int>& kids, int unfairness, int idx) {
        if(idx >= cookies.size()) {
            return unfairness;
        }
        int result = INT_MAX, temp = unfairness;
        for(int i = 0; i < k; i++) {
            kids[i] += cookies[idx];
            if(kids[i] > unfairness)
                unfairness = kids[i];
            result = min(result, func(cookies, k, kids, unfairness, idx + 1));
            kids[i] -= cookies[idx];
            unfairness = temp;
        }
        return result;
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> kids(k, 0);
        return func(cookies, k, kids, 0, 0);
    }
};