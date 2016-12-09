class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int length = b.size();
        if(length == 0)
        {
            return 1;
        }
        
        a = a%1337;
        
        int firstExpression = superPow(a, b[length - 1]);
        b.pop_back();
        int secondExpression = superPow(a, b);
        
        if(length > 1)
        {
            secondExpression = superPow(secondExpression, 10);
        }
        
        return firstExpression * secondExpression % 1337;
    }
    
    int superPow(int a, int k)
    {
        int output = 1;
        for(int i = 0; i < k; i ++)
        {
            output = (output * a) % 1337;
        }
        
        return output;
    }
};