class Solution {
public:
    bool isMatch(string s, string p) {
        int sLength = s.size();
        int pLength = p.size();
        
        vector<vector<bool>> dp(pLength + 1, vector<bool>(sLength + 1));

        dp[0][0] = true;
        
        for(int i = 1; i <= pLength; i ++)
        {
            if(p[i - 1] == '*')
            {
                dp[i][0] = dp[i - 1][0];
            }
        }
        
        for(int i = 1; i <= pLength; i++)
        {
            for(int j = 1; j <= sLength; j ++)
            {
                if(p[i - 1] == '*')
                {
                    bool result = dp[i - 1][j];
                    result |= dp[i][j - 1];
                    dp[i][j] = result;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - 1] && (p[i - 1] == '?' || p[i - 1] == s[j - 1]);
                }
            }
        }
        
        return dp[pLength][sLength];
    }
};