int limit = INT_MAX / 10;
int lastDigit = INT_MAX % 10;
        
class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN)
        {
            return 0;
        }
        
        bool negative = x < 0;
        x = x < 0? x * -1 : x;

        int reverse = 0;

        while(x)
        {
            int digit = x % 10;
            if(reverse > limit)
            {
                return 0;
            }
            else if(reverse == limit)
            {
                if(digit > lastDigit)
                {
                    return 0;
                }
            }
            
            reverse *= 10;
            reverse += digit;
            x /= 10;
        }
        
        if(negative)
        {
            reverse *= -1;
        }
        
        return reverse;
    }
};