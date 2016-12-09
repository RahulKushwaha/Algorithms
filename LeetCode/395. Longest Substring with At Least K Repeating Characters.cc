class Solution {
public:
    int longestSubstring(string s, int k) {
        int output = 0;
        longestSubstring(s, k, output);
        
        return output;
    }
    
    void longestSubstring(string s, int k, int &longest)
    {
        int length = s.size();

        if(length == 0)
        {
            return;
        }
        
        int freq[26] = {0};
        
        for(int i = 0; i < length; i ++)
        {
            freq[s[i] - 'a'] ++;
        }
        
        string ss;
        for(int i = 0; i < length; i ++)
        {
            if(freq[s[i] - 'a'] < k)
            {
                longestSubstring(ss, k, longest);
                ss.clear();
            }
            else
            {
                ss += s[i];
            }
        }
        
        if(ss.size() == length)
        {
            longest = max(longest, length);
        }
        else
        {
            longestSubstring(ss, k, longest);
        }
    }
};