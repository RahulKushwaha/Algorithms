class Solution {
public:
    double myPow(double x, int n) {
        
        unsigned exponent;
        if(n < 0)
        {
            exponent = n * (-1);
            x = 1 / x;
        }
        else
        {
            exponent = n;
        }
        
        return myPow(x, exponent);
    }
    
    double myPow(double x, unsigned n)
    {
        if(n == 0)
        {
            return 1;
        }
        
        if(n == 1)
        {
            return x;
        }
        
        if(n % 2 == 0)
        {
            double t = myPow(x, n/2);
            return t*t;
        }
        else
        {
            return x * myPow(x, n - 1);
        }
        
    }
};