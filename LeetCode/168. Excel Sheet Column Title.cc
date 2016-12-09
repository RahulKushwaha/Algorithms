class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while(n != 0)
        {
            n--;
            // As we are adding 'A' which already holds the value 1, we decrement the value of n in the preceding line.
            char temp = 'A' + (char)(n % 26);
            n/= 26;
            result = temp + result;
        }
        
        return result;
    }
};