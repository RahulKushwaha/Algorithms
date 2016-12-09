class Solution {
public:
    int longestPalindrome(string s) {
        int freq[256] = {0};
        
        for(int i = 0; i < s.size(); i ++)
        {
            freq[s[i]]++;
        }
        
        int output = 0;
        bool odd = false;
        for(int i = 0; i < 256; i ++)
        {
            if(freq[i] % 2)
            {
                output += freq[i] - 1;
                odd = true;
            }
            else
            {
                output += freq[i];
            }
        }
        
        if(odd)
        {
            output ++;
        }
        
        return output;
    }
};