class Solution {
public:
    long getDigitsSquaredSum(long n)
    {
        long sum = 0;
        while(n != 0)
        {
            long temp = n % 10;
            sum += (temp * temp);
            n /= 10;
        }
        
        return sum;
    }
    
    bool isHappy(int n) {
        long num = n;
        unordered_set<long> numbersVisited;
        numbersVisited.insert(num);
        
        for(; num != 1;)
        {
            num = getDigitsSquaredSum(num);
            unordered_set<long>::iterator itr = numbersVisited.find(num);
            
            if(itr == numbersVisited.end())
            {
                numbersVisited.insert(num);
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }
};