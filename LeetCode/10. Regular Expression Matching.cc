class Solution {
public:
    bool isMatch(string s, string p) {
        int lengthS = s.size();
        int lengthP = p.size();
        
        bool dp[lengthP + 1][lengthS + 1];
        for(int i = 0; i <= lengthP; i ++ )
        {
            for(int j = 0; j <= lengthS; j ++)
            {
                dp[i][j] = false;
            }
        }
        
        dp[0][0] = true;
        
        for(int i = 1; i <= lengthP; i ++)
        {
            if(p[i - 1] == '*')
            {
                bool result = dp[i - 2][0];
                if(p[i - 2] == '.')
                {
                    result |= dp[i - 1][0];
                }
                
                dp[i][0] = result;
            }
        }
        
        for(int i = 1; i <= lengthP; i ++)
        {
            for(int j = 1; j <= lengthS; j ++)
            {
                if(p[i - 1] == '*')
                {
                    bool result = dp[i - 2][j];
                    
                    result |= (dp[i][j - 1] && (p[i - 2] == s[j - 1] || p[i - 2] == '.'));
                    
                    dp[i][j] = result;
                }
                else if(p[i - 1] == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(p[i - 1] == s[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        
        return dp[lengthP][lengthS];
    }
};