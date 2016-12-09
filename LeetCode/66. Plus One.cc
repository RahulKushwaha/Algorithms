class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == 0)
        {
            return digits;
        }
        
        int carry = 0;
        
        digits[digits.size() - 1]++;
        
        for(int i = digits.size() - 1; i >= 0; i --)
        {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
            
            if(carry == 0)
            {
                break;
            }
        }
        
        if(carry > 0)
        {
            digits.insert(digits.begin(), carry);
        }
        
        return digits;
    }
};