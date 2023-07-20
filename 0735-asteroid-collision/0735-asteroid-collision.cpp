class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        stack<int> stk;
        for(int i = 0; i < asteroids.size(); i++) {
            while(i < asteroids.size() && !stk.empty() && stk.top() > 0 && asteroids[i] < 0) {
                if(stk.top() == -asteroids[i]) {
                    stk.pop();
                    i++;
                }
                else if(stk.top() > -asteroids[i]) {
                    i++;
                }
                else {
                    stk.pop();
                }
            }
            if(i < asteroids.size())
                stk.push(asteroids[i]);
        }
        while(!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};















// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         vector<int> result;
//         result.push_back(asteroids[0]);
//         int l = 0, r = 1;

//         while(r < asteroids.size()) {
//             while(l >= 0 && r < asteroids.size() && asteroids[l] >= 0 && asteroids[r] < 0) {
//                 if(result.back() + asteroids[r] == 0) {
//                     result.pop_back();
//                     l--;
//                     r++;
//                 }
//                 if(result.back() + asteroids[0] > 0) {
//                     break;
//                 }
//                 else {
//                     result.pop_back();
//                     l--;
//                 }
//             }
//             if(r < asteroids.size())
//                 result.push_back(asteroids[r]);
//             r++;
//         }
//         return result;
//     }
// };