class Solution 
{
public:
    int minimumAverageDifference(vector<int>& nums) 
    {
        int n = nums.size();
        vector<long> uno, dos;
        long temp, sum = 0;
        long ans = INT_MAX;
        int ret = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            uno.push_back(sum/(i+1));
        }
        for(int i = 0; i < n; i++)
        {
            sum -= nums[i];
            if(n - i - 1 > 0)
                dos.push_back(sum / (n - i - 1));
            else
                dos.push_back(0);
        }
        for(int i = 0; i < n; i++)
        {
            temp = abs(uno[i] - dos[i]);
            if(temp < ans)
            {
                ans = temp;
                ret = i;
            }
        }
        return ret;
    }
};