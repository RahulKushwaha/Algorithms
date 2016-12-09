class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> output;
        if(n <= 0)
        {
            return output;
        }
        
        output.resize(n + 1);
        int index = 0;
        
        generateNumbers(n, 0, &output[0], index);
        
        output.erase(output.begin());
        
        return output;
    }
    
    void generateNumbers(int n, int number, int* output, int& index)
    {
        if(number > n)
        {
            return;
        }
        
        if(number <= n)
        {
            output[index ++] = number;
        }
        
        int nextNum = number * 10;
        int temp = 0;
        for(int i = 0; i < 10; i ++)
        {
            if(number == 0 && i == 0)
            {
                continue;
            }
            
            temp = nextNum + i;
            if(temp > n)
            {
                continue;
            }
            
            generateNumbers(n, temp, output, index);   
        }
    }
};