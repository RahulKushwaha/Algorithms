class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int counter = 0;
        
        while(n != 0)
        {
            counter++;
            n = n ^ (n & (-n));
        }
        
        return counter;
    }
};