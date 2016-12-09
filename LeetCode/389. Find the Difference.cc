class Solution {
public:
    char findTheDifference(string s, string t) {
        int sFreq[256] = {0};
        int tFreq[256] = {0};
        
        for(int i = 0; i < s.size(); i ++)
        {
            sFreq[s[i]] ++;
        }
        
        for(int i = 0; i < t.size(); i ++)
        {
            tFreq[t[i]] ++;
        }
        
        for(int i = 0; i < 256; i ++)
        {
            if(sFreq[i] != tFreq[i])
            {
                return (char)i;
            }
        }
        
        return 255;
    }
};