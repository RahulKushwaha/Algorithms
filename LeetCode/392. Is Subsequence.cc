class Solution {
public:
    bool isSubsequence(string s, string t) {
        int tLength = t.size();
        int sLength = s.size();

        int i = 0, j = 0;
        
        while(i != sLength)
        {
            while(j < tLength && t[j] != s[i])
            {
                j ++;
            }
            
            if(j == tLength)
            {
                return false;
            }
            
            j ++;
            i ++;
        }
        
        return i == sLength;
    }
};