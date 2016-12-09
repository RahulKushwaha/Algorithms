class Solution {
public:
    int mySqrt(int x) {
        
        if(x == 1 || x == 0)
        {
            return x;
        }
        
        int l = 0, u = x;
        int result;
        
        while(l <= u)
        {
            long long mid = ((u - l)/ 2) + l;
            long long product = mid * mid;

            if(product == x)
            {
                return mid;
            }
            else if(product < x)
            {
                result = mid;
                if(l == u)
                {
                    break;
                }
                
                l = mid + 1;
            }
            else
            {
                u = mid - 1;
            }
        }
        
        return result;
        
    }
};