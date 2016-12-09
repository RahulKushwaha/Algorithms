class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lookup;
        
        int length = s.size();
        if(length == 0)
        {
            return 0;
        }
        
        int maxLength = 0;
        int startIndex = 0;
        
        s += '$';
        lookup.insert(pair<char, int>('$', length));

        for(int i = 0; i <= length; )
        {
            unordered_map<char, int>::iterator itr = lookup.find(s[i]);
            
            if(itr == lookup.end())
            {
                lookup.insert(pair<char, int>(s[i], i));
                i ++;
            }
            else
            {
                lookup.erase(itr);
                
                int index = itr->second;
                int currentLength = i - startIndex;
                if(currentLength > maxLength)
                {
                    maxLength = currentLength;
                }
                
                for(int a = index; a >= startIndex; a --)
                {
                    lookup.erase(s[a]);
                }
                
                startIndex = index + 1;
            }
        }
        
        return maxLength;
    }
};