class Solution {
public:

    unordered_map<long, long> lookup;
    int integerReplacement(int n)
    {
        return integerReplacement((long)n);
    }
    
    long integerReplacement(long n) {
        if(n == 0 || n == 1)
        {
            return 0;
        }
        
        unordered_map<long, long>::iterator itr = lookup.find(n);
        if(itr != lookup.end())
        {
            return itr->second;
        }
        
        long result = 0;
        
        if(n % 2 == 0)
        {
            result = 1 + integerReplacement(n / 2);
        }
        else
        {
            result = 1 + min(integerReplacement(n - 1) , integerReplacement(n + 1));
        }
        
        lookup[n] = result;
        
        return result;
    }
};