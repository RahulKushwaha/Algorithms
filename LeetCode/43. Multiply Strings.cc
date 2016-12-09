class Solution {
public:
    string multiply(string num1, string num2) {
        int length1 = num1.size();
        int length2 = num2.size();
        if(length1 == 0 || length2 == 0)
        {
            return "0";
        }
        
        if(length1 == 1)
        {
            if(num1[0] == '0')
            {
                return "0";
            }
        }
        
        if(length2 == 1)
        {
            if(num2[0] == '0')
            {
                return "0";
            }
        }
        
        int length = 2048;
        int output[length] = {0};
        
        int counter = 0;
        for(int i = length1 -1; i >= 0; i --)
        {
            int k = length - 1 - counter;
            counter ++;
            for(int j = length2 - 1; j >= 0; j--, k --)
            {
                output[k] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        int carry = 0;
        for(int l = length - 1; l >= 0; l --)
        {
            output[l] += carry;
            carry = output[l] / 10;
            output[l] %= 10;
        }
        
        stringstream str;
        int i = 0;
        for(; i < length; i++ )
        {
            if(output[i] != 0)
            {
                break;
            }
        }
        
        for(; i < length; i ++)
        {
            str<<output[i];
        }
        
        return str.str();
    }
};