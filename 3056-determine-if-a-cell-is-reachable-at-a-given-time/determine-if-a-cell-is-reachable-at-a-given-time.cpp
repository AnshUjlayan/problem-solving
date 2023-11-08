class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dist = max(abs(fx - sx), abs(fy - sy));
        return dist == 0 ? t != 1 : dist <= t;
    }
};