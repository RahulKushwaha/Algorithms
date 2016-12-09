class Solution {
public:
    bool canPermutePalindrome(string s) {
        int length = s.size();
        if(length == 0)
        {
            return true;
        }
        
        int freq[256] = {0};
        
        for(int i = 0; i < length; i ++)
        {
            freq[s[i]]++;
        }
        
        int numOdd = 0;
        
        for(int i = 0; i < 256; i ++)
        {
            if(freq[i] % 2 != 0)
            {
                numOdd++;
            }
        }
        
        return numOdd < 2;
    }
};