class Solution 
{
public:
    string frequencySort(string s) 
    {
        unordered_map<char,int> ump;
        for (char x : s)
            ump[x]++;
        
        set<pair<int,char>> pq;
        for (auto[ch,freq] : ump)
            pq.insert({-freq, ch});
        
        string ans = "";
        for (auto[freq,ch] : pq)
            ans += string(-freq, ch);
        
        return ans;
    }
};