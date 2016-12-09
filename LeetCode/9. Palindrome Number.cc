class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0)
        {
            return false;
        }
        
        int y = 0;
        int num = x;
        
        while(num != 0)
        {
            y *= 10;
            y += num % 10;
            num /= 10;
        }
        
        return y == x;
    }
};