class Solution {
public:
    int findNthDigit(int n) {
        long long init = 9;
        long long digits = 1;
        long long current = 0;
        long long remaingingDigits = n;
        long long number = 0;
        
        while(true)
        {
            long long next = init * pow(10, digits - 1) * (digits); 
            if(n >= current && n <= next)
            {
                long long ans = number + remaingingDigits / digits;
                string temp = to_string(ans);
                long long digitCounter = remaingingDigits % digits;
                char ch = temp[temp.size() - 1];
                long long i = 0;
                temp = to_string(ans + 1);

                while(digitCounter)
                {
                    ch = temp[i];
                    i ++ ;
                    digitCounter --;
                }

                return ch - '0';
            }
            
            number = pow(10, digits) - 1;
            current += next;
            digits ++;
            remaingingDigits = n - current;
        }
        
        return -1;
    }
};