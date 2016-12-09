// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 0, h = n;
        while(l <= h)
        {
            int mid = ((h - l) >> 1) + l;
            int result = guess(mid);
            if(result == 0)
            {
                return mid;
            }
            
            if(l == h)
            {
                break;
            }
            
            if(result == -1)
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        
        return -1;
    }
};