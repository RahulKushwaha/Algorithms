class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 0)
        {
            return 0;
        }
        
        vector<int> primes {2, 3, 5};
        
        int length = primes.size();

        int factors[n];
        int indices[length] = {0};
        
        factors[0] = 1;
        
        for(int i = 1; i < n; i ++)
        {
            int current = INT_MAX;
            for(int j = 0; j < length; j ++)
            {
                long currentProduct = primes[j] * factors[indices[j]];
                if(currentProduct < current)
                {
                    current = currentProduct;
                }
            }
            
            factors[i] = current;
            
            for(int j = 0; j < length; j ++)
            {
                if(primes[j] * factors[indices[j]] == current)
                {
                    indices[j] ++;
                }
            }
        }
        
        return factors[n - 1];
    }
};