class Solution {
public:
    string toHex(int num) {
        string output;
        int counter = 0;
        do
        {
            char mask = 0xf;
            int hexaDigit = mask&num;
            char currentChar = hexaDigit < 10 ? '0' + hexaDigit : 'a' + hexaDigit - 10;
            output = currentChar + output;
            num >>= 4;
            counter ++;
        }while(counter < 8 && num);
        
        return output;
    }
};