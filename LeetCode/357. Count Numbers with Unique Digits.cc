class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
        {
            return 1;
        }
        
        int total = 10;
        if(n == 1)
        {
            return total;
        }
        
        total = 91;
        if(n == 2)
        {
            return total;
        }
        
        for(int i = 3; i <= 10 && i <= n; i ++)
        {
            int numbers = 81;
            int init = 8;
            for(int j = 3; j <= i; j ++)
            {
                numbers *= init;
                init --;
            }
            
            total += numbers;
        }
        
        return total;
    }
};