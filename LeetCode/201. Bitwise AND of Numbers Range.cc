class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        long lower = 1;

        while((lower << 1) < n)
        {
            lower = lower<<1;
        }
        
        if(m < lower)
        {
            return 0;
        }
        
        int ans = m;

        for(int i = ans; i <= n ; i ++)
        {
            ans &= i;
            if(i == INT_MAX)
            {
                break;
            }
        }
        
        return ans;
    }
};