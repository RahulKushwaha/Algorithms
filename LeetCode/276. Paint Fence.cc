class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0 || k == 0)
        {
            return 0;
        }
        
        int same = 0;
        int diff = k;
        
        for(int i = 1; i < n; i ++)
        {
            int newDiff = diff * (k - 1) + same * (k - 1);
            
            same = diff;
            diff = newDiff;
        }
        
        return same + diff;
    }
};