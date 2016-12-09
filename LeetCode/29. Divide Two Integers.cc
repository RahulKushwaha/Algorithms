class Solution {
public:
    long binaryDivide(long dividend, long divisor)
    {
        long total = 0;
        while(dividend >= divisor)
        {
            long counter = 1;
            long deno = divisor;
            
            while(dividend >= deno)
            {
                dividend -= deno;
                deno += deno;
                
                total += counter;
                
                counter += counter;
            }
        }
        
        return total;
    }
    
    int divide(int dividend, int divisor) {
        bool divisorNegative = divisor < 0; 
        bool dividendNegative = dividend < 0;
        
        long num = dividendNegative ? -1 * (long)dividend : (long)dividend;
        long deno = divisorNegative ? -1 * (long)divisor : (long)divisor;

        if(num < deno)
        {
            return 0;
        }
        
        long counter = binaryDivide(num, deno);        
        
        if((divisorNegative && dividendNegative == false) || (divisorNegative == false && dividendNegative))
        {
            counter *= -1;
        }
        
        return counter > INT_MAX ? INT_MAX : counter;
    }
};