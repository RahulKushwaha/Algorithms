class Solution {
public:
    int getNumber(string& abbr, int& index)
    {
        int i = 0;
        for(; index < abbr.size() && isdigit(abbr[index]);)
        {
            i *= 10;
            i += abbr[index++] - '0';
        }
        
        return i;
    }
    
    bool validWordAbbreviation(string word, string abbr) {
        int length = word.size();
        int abbrLength = abbr.size();
        int i = 0, j = 0;
        
        for(; i < length && j < abbrLength;)
        {
            if(isalpha(abbr[j]))
            {
                if(abbr[j] != word[i])
                {
                    return false;
                }
                
                i ++;
                j ++;
            }
            else if(abbr[j] == '0')
            {
                return false;
            }
            else
            {
                int offset = getNumber(abbr, j);
                if(offset == 0)
                {
                    return false;
                }
                
                i += offset;
            }
        }
        
        if(length == i && abbrLength == j)
        {
            return true;
        }
        
        return false;
    }
};