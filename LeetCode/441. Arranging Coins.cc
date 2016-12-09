class Solution {
public:
    int arrangeCoins(int n) {
        long k = 0;
        long sum = 0;
        int prev = k;
        
        while(sum <= n)
        {
            prev = k ++;
            sum = (k * k + k) / 2;
        }
        
        return prev;
    }
};