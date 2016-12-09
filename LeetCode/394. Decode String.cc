class Solution {
public:
    string decodeString(string s) {
        int initialIndex = 0;
        return decodeString(s, initialIndex);
    }
    
    int getNum(string& s, int& index)
    {
        int num = 0, length = s.size();
        while(index < length && isdigit(s[index]))
        {
            num *= 10;
            num += s[index ++] - '0';
        }
        
        return num;
    }
    
    string decodeString(string s, int& index)
    {
        stringstream output;
        
        for(; index < s.size(); )
        {
            if(isdigit(s[index]))
            {
                int multiplier = getNum(s, index);
                index ++;
                
                string text = decodeString(s, index);
                for(int j = 0; j < multiplier; j ++)
                {
                    output<<text;
                }
            }
            else if(isalpha(s[index]))
            {
                output<<s[index ++];
            }
            else
            {
                index ++;
                break;
            }
        }
        
        return output.str();
    }
};