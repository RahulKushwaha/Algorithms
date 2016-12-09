class Solution {
public:
    int numDecodings(string s) {
        int length = s.size();
        if(!length || s[0] == '0')
        {
            return 0;
        }
        
        int last = 1, secondLast = 1;
        
        for(int i = 1; i < length; i ++)
        {
            int total = 1;
            
            char currentCh = s[i];
            char lastCh = s[i - 1];
                
            if(currentCh == '0')
            {
                if(lastCh == '1' || lastCh == '2')
                {
                    total = secondLast;
                }
                else
                {
                    return 0;   
                }
            }
            else if(lastCh == '1' || (lastCh == '2' && (currentCh - '0' < 7)))
            {
                total = secondLast + last;
            }
            else
            {
                total = last;
            }
            
            secondLast = last;
            last = total;
        }

        return last;
    }
};