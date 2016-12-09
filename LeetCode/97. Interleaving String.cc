class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int z = s3.size();
        
        if(m + n != z)
        {
            return false;
        }
        
        bool lookup[m + 1][n + 1] = {0};
        
        for(int i = 0; i <= m; i ++)
        {
            for(int j = 0; j <= n; j ++)
            {
                if(i == 0 && j == 0)
                {
                    lookup[i][j] = 1;
                }
                else if(i == 0 && s3[j - 1] == s2[j - 1])
                {
                    lookup[i][j] = lookup[i][j - 1];
                }
                else if(j == 0 && s2[i - 1] == s3[i - 1])
                {
                    lookup[i][j] = lookup[i - 1][j];
                }
                else if(s2[j - 1] != s3[i + j - 1] && s1[i - 1] == s3[i + j - 1])
                {
                    lookup[i][j] = lookup[i - 1][j];
                }
                else if(s1[i - 1] != s3[i + j - 1] && s2[j - 1] == s3[i + j - 1])
                {
                    lookup[i][j] = lookup[i][j - 1];
                }
                else if(s1[i - 1] == s3[i + j - 1] && s2[j - 1] == s3[i + j - 1])
                {
                    lookup[i][j] = (lookup[i - 1][j] || lookup[i][j - 1]);
                }
            }
        } 

        
        return lookup[m][n];
    }
};