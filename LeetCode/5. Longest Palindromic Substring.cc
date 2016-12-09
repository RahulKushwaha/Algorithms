class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        string output;
        
        if(length == 0)
        {
            return output;
        }
        
        bool lookup[1000][1000] = {false};
        for(int i = 0; i < length; i ++)
        {
            lookup[i][i] = true;
        }
        
        int palindromeIndex = 0;
        int maxLength = 1;
        
        for(int i = 0; i < length - 1; i ++)
        {
            if(s[i] == s[i + 1])
            {
                lookup[i][i + 1] = true;
                palindromeIndex = i;
                maxLength = 2;
            }
        }
        
        for(int len = 2; len < length; len ++)
        {
            for(int i = 0; i < length - len; i ++)
            {
                int j = i + len;
                if(lookup[i + 1][j - 1] && s[i] == s[j])
                {
                    lookup[i][j] = true;
                    palindromeIndex = i;
                    maxLength = j - i + 1;
                }
            }
        }
        
        return s.substr(palindromeIndex, maxLength);
    }
};