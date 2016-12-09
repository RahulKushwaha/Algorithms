int min(int a, int b)
{
    return a < b? a: b;
}
class Solution {
public:
    int minCut(string s) {
        int length = s.size();
        if(length == 0)
        {
            return 0;
        }
        
        bool dp[2000][2000] = {0};
        
        for(int i = 0; i < length; i++)
        {
            dp[i][i] = 1;
        }
        
        for(int i = 0; i < length - 1; i ++)
        {
            if(s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;
            }
        }
        
        for(int len = 2; len < length; len ++)
        {
            for(int i = 0; i < length - len; i ++)
            {
                int j = i + len;
                
                if(s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = 1;
                }
            }
        }
        
        int count[length] = {0};
        
        for(int i = 0; i < length; i ++)
        {
            if(dp[0][i])
            {
                count[i] = 0;
            }
            else
            {
                count[i] = INT_MAX;
                for(int j = 0; j <= i; j ++)
                {
                    if(dp[j + 1][i] && 1 + count[j] < count[i])
                    {
                        count[i] = 1 + count[j];
                    }
                }
            }
        }
        
        return count[length - 1];
    }
};