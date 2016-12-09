class Solution {
public:
    int numDistinct(string s, string t) {
        int lengthS = s.size();
        int lengthT = t.size();
        
        if(lengthS == 0 || lengthT == 0)
        {
            return 0;
        }
        
        int dp[lengthT + 1][lengthS + 1];
        
        for(int i = 0; i <= lengthT; i ++)
        {
            for(int j = 0; j <= lengthS; j ++)
            {
                dp[i][j] = 0;
            }
        }
        
        for(int j = 0; j <= lengthS; j ++)
        {
            dp[0][j] = 1;
        }
        
        for(int i = 1; i <= lengthT; i ++)
        {
            for(int j = 1; j <= lengthS; j ++)
            {
                if(t[i - 1] == s[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
                
                //cout<<dp[i][j]<<" ";
            }
            
            //cout<<endl;
        }
        
        return dp[lengthT][lengthS];
        
    }
};