class Solution 
{
public:
    string frequencySort(string s) 
    {
        unordered_map<char,int> ump;
        for (char x : s)
            ump[x]++;
        
        set<pair<int,char>> pq;
        for (auto[ch,c] : ump)
            pq.insert({-c, ch});
        
        string ans = "";
        for (auto[c,ch] : pq)
            ans += string(-c, ch);
        
        return ans;
    }
};