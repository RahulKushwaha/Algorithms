class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 0)
        {
            return false;
        }
        
        if(num == 1)
        {
            return true;
        }
        
        int l = 1; 
        int h = num;
        
        while(l <= h)
        {
            int mid = ((h - l) / 2) + l;
            
            int product = num / mid;
            bool remainder = num % mid;
            if(product == mid && remainder == 0)
            {
                return true;
            }
            
            if(l == h)
            {
                return false;
            }
            
            if(mid < product)
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        
        return false;
    }
};