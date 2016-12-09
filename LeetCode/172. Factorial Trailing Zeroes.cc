class Solution {
public:
    int trailingZeroes(int n) {
        
        int numberOfZero = 0;
        
        for(int i = 5; n != 0;)
        {
            numberOfZero += n = n / i;
        }
        
        return numberOfZero;
    }
};