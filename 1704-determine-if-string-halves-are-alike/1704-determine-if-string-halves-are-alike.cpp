class Solution 
{
public:
    bool halvesAreAlike(string s) 
    {
        set<char> st{'a','e','i','o','u','A','E','I','O','U'};
        int i = 0, count = 0, x = s.length();
        for(; i<x/2; i++)
        {
            auto p = st.find(s[i]);
            if(p!=st.end())
                count++;
        }
        for(; i<x; i++)
        {
            auto p = st.find(s[i]);
            if(p!=st.end())
                count--;
        }
        if (count == 0)
            return true;
        return false;
    }
};