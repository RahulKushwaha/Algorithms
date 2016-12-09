class Solution {
public:
    int firstUniqChar(string s) {
        int freq[256] = {0};
        
        int length = s.size();
        for(int i = 0; i < length; i ++)
        {
            freq[s[i]] ++;
        }
        
        for(int i = 0; i < length; i ++)
        {
            if(freq[s[i]] == 1)
            {
                return i;
            }
        }
        
        return -1;
    }
};