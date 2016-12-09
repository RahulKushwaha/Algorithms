class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string output;
        
        if(denominator == 0)
        {
            output += '0';
            return output;
        }
        
        bool numNegative = numerator < 0;
        bool denoNegative = denominator < 0;
        
        bool negative = (numNegative ^ denoNegative);
        
        long beforeDecimal;
        
        long num = numerator;
        long deno = denominator;
        
        num = numNegative ?  -num : num;
        deno = denoNegative ? -deno : deno;
        
        long remainder = num % deno;
        bool haveFraction = remainder != 0;
        
        beforeDecimal = num / deno;
        
        output = to_string(beforeDecimal);
        
        if(negative)
        {
            output = "-" + output;
        }
        
        if(haveFraction == false)
        {
            return beforeDecimal == 0 ? (negative ? output.substr(1) : output) : output;
        }
        
        output += '.';
        
        unordered_map<long, int> remainders;
        
        string fraction;
        string recurring;
        int counter = 0;
        
        for(; remainder != 0;)
        {
            unordered_map<long, int>::iterator itr = remainders.find(remainder);
            if(itr == remainders.end())
            {
                remainders.insert(make_pair(remainder, counter ++));
                remainder *= 10;
                fraction += to_string(remainder / deno);
                remainder = remainder % deno;
            }
            else
            {
                int fractionLength = fraction.size();
                int insertIndex = itr->second;
                fraction.insert(fraction.begin() + insertIndex, '(');
                fraction += ')';
                break;
            }
        }
        
        output += fraction;
       
        return output;
    }
};