class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int length = s.size();
        
        if(length == 0)
        {
            return 0;
        }
        
        unordered_map<char, int> lookup;
        int i = 0, j = 0, k = 2;
        int totalCount = 0, diffCount = 0, maxLength = 0;
        
        while(i != length)
        {
            if(diffCount <= k)
            {
                unordered_map<char, int>::iterator itr = lookup.find(s[i]);
                if(itr == lookup.end())
                {
                    lookup[s[i]] = 1;
                    diffCount ++;
                }
                else
                {
                    lookup[s[i]] ++;
                }
                
                totalCount ++;
                i ++;
            }
            else
            {
                unordered_map<char, int>::iterator itr = lookup.find(s[j]);
                if(itr->second == 1)
                {
                    lookup.erase(itr);
                    diffCount --;
                }
                else
                {
                    itr->second --;
                }
                
                totalCount --;
                j ++;
            }
            
            if(diffCount <= k)
            {
                maxLength = max(maxLength, totalCount);
            }
        }
        
        return maxLength;
    }
};