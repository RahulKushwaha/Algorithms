class Solution {
public:
    int addDigits(int num) {
        
        if(num < 10)
        {
            return num;
        }
        
        int newNum = 0;
        for(int i = num; i != 0; i /= 10)
        {
            newNum += i % 10;
        }
        
        return addDigits(newNum);
    }
};