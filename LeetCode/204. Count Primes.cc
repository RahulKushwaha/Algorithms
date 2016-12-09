class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1)
        {
            return 0;
        }
        
        vector<bool> primes(n + 1, true);
        
        primes[0] = false;
        primes[1] = false;
        
        int limit = sqrt(n);
        
        for(int i = 2; i <= limit; i ++)
        {
            for(int j = i; i * j < n ; j++)
            {
                primes[i * j] = false;
            }
        }
        
        int counter = 0;
        for(int i = 1; i < n; i ++)
        {
            if(primes[i])
            {
                counter ++;
            }
        }
        
        return counter;
    }
};