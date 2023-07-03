class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size())
            return false;
        unordered_map<char,int> ump1, ump2;
        int error = 0;
        bool duo = false;
        for(int i = 0; i < goal.size(); i++) {
            ump1[s[i]]++;
            ump2[goal[i]]++;
            error += s[i] != goal[i] ? 1 : 0;
            if(ump1[s[i]] == 2)
                duo = true;
        }
        if(s == goal)
            return duo;
        return error == 2 && ump1 == ump2;
    }
};