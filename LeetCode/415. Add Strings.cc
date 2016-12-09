class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0, i = num1.size() - 1, j = num2.size() - 1;
        stringstream ss; 
        
        for(; j >= 0 || i >= 0 || carry; i --, j --)
        {
            int a = i >= 0 ? num1[i] - '0' : 0;
            int b = j >= 0 ? num2[j] - '0' : 0;
            int sum = a + b + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            ss<<(sum);
        }
        
        string output = ss.str();
        reverse(output.begin(), output.end());
        
        return output;
    }
};