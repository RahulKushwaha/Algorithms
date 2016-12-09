int max(int a, int b)
{
    return a > b ? a : b;
}

class Solution {
public:
    int integerBreak(int n) {
        vector<int> lookup;
        lookup.resize(n + 1);
        
        lookup[0] = 0;
        lookup[1] = 1;
        lookup[2] = 1;
        
        // To find the maximum product using the numbers that sum up that number.
        // We can start fill up a lookup table from 1 -- n in a bottom up manner.
        // The lookup table will contain the maximum so that it can be used to answer for bigger numbers.
        for(int i = 3; i <= n; i ++)
        {
            int m = INT_MIN;
            // i can be formed by j + i - j where values of j range from 1 to i/2
            for(int j = 1; j <= i/ 2; j ++)
            {
                int currentMax = max(j, lookup[j]) * max(lookup[i - j],  i - j);
                if(m < currentMax)
                {
                    m = currentMax;
                }
            }
            
            lookup[i] = m;
        }
        
        return lookup[n];
    }
};