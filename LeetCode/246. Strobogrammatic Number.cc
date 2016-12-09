class Solution {
public:
    bool isStrobogrammatic(string num) {
        int length = num.size();
        if(length == 0)
        {
            return true;
        }
        
        for(int i = 0; i < length; i ++)
        {
            int digit = num[i] - '0';
            if(digit == 2 || digit == 3 ||digit == 4 ||digit == 5 || digit == 7)
            {
                return false;
            }
        }
        
        int i = 0, j = length - 1;
        
        while(i <= j)
        {
            int digit1 = num[i] - '0';
            int digit2 = num[j] - '0';
            
            if(i == j)
            {
                if(digit1 == 6 || digit2 == 9)
                {
                    return false;
                }
            }
            
            if((digit1 == 8 && digit2 == 8) ||
               (digit1 == 1 && digit2 == 1) ||
               (digit1 == 0 && digit2 == 0) ||
               (digit1 == 6 && digit2 == 9) ||
               (digit1 == 9 && digit2 == 6))
               {
                   i ++; 
                   j --;
                   continue;
               }
            
            return false;
        }
        
        return true;
    }
};