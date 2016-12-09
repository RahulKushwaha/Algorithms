class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& elements) {
        int length = elements.size();
        if(length < 2)
        {
            return 0;
        }
        
        vector<int> differences (length - 1);
        
        for(int i = 1; i < length; i ++)
        {
            differences[i - 1] = elements[i] - elements[i - 1];
        }
        
        int output = 0;
        int prev = 0;
        for(int i = 0; i < length; i ++)
        {
            if(i == length - 1 || differences[i] != differences[prev])
            {
                if(prev - i != 1)
                {
                    int n =  i - prev;
                    output += (n * (n - 1)) / 2;
                }
                
                prev = i;
            }
        }
        
        return output;
    }
};