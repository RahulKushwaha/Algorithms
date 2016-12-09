class Solution {
public:
    string minWindow(string s, string t) {
        int sLength = s.size();
        int tLength = t.size();
        string output;

        if(sLength == 0 || tLength == 0)
        {
            return output;
        }
        
        int freq[256] = {0};
        
        for(int i = 0; i < tLength; i ++)
        {
            freq[t[i]] ++;
        }
        
        int diffCount = tLength;
        
        int i = 0, j = 0;
        int currentDiffcount = 0;
        
        int sfreq[256] = {0};
        int ans = INT_MAX;
        char ch;
        
        while(true)
        {
            if(currentDiffcount == diffCount)
            {
                if(ans > i - j)
                {
                    ans = i - j;
                    output = s.substr(j, i - j);
                }
                
                ch = s[j];
                sfreq[ch] --;
                if(sfreq[ch] < freq[ch])
                {
                    currentDiffcount --;
                }
                
                j ++;
            }
            else if(currentDiffcount < diffCount)
            {
                if(i == sLength)
                {
                    break;
                }
                
                ch = s[i];
                sfreq[ch] ++;
                
                if(sfreq[ch] <= freq[ch])
                {
                    currentDiffcount ++;
                }
                i ++;
            }
        }
        
        return output;
    }
};