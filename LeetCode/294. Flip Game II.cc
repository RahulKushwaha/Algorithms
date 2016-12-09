class Solution {
public:
    bool canWin(string s)
    {
        bool flag = false;
        for(int i = 0; i + 1 < s.size(); i ++)
        {
            if(s[i] == '+' && s[i + 1] == '+')
            {
                s[i] = '-';
                s[i + 1] = '-';
                
                if(!canWin(s))
                {
                    return true;
                }
                
                s[i] = '+';
                s[i + 1] = '+';
            }
        }
        
        return false;
    }
};