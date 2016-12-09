class Solution {
public:
    int climbStairs(int n) {
        if(n < 3)
        {
            return n;
        }
        
        int a = 1, b = 2, c, counter = 2;
        while(counter < n)
        {
            c = b + a;
            a = b;
            b = c;
            counter ++;
        }
        
        return c;
    }
};