class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> output;
        
        if(n <= 0)
        {
            return output;
        }
        
        if(n == 1)
        {
            output.push_back("0");
            output.push_back("1");
            output.push_back("8");
            
            return output;
        }
        
        int digits[5];
        digits[0] = 0;
        digits[1] = 1;
        digits[2] = 6;
        digits[3] = 8;
        digits[4] = 9;
        
        vector<int> current;
        bool odd = n % 2 != 0;
        n = odd ? n / 2 + 1 : n / 2;
        generateCombinations(n, 0, odd, digits, 5, current, output);
        
        return output;
    }
    
    void generateCombinations(int n,
                              int index,
                              bool odd,
                              int * digits,
                              int limit,
                              vector<int>& currentOutput, 
                              vector<string>& output)
    {
        int currentOutputSize = currentOutput.size();
        
        if(currentOutputSize == n)
        {
            int length = n - 1;
            if(odd)
            {
                length = n - 2;
            }
            
            stringstream str;
            for(int i = 0; i < currentOutputSize; i ++)
            {
                str<<currentOutput[i];
            }
            
            for(int i = length; i >= 0; i --)
            {
                if(currentOutput[i] == 6)
                {
                    str<<'9';
                }
                else if(currentOutput[i] == 9)
                {
                    str<<'6';
                }
                else
                {
                    str<<currentOutput[i];
                }
            }

            output.push_back(str.str());
            return;
        }
        
        for(int i = 0; i < 5; i ++)
        {
            if(currentOutputSize == 0 && i == 0)
            {
                continue;
            }
            
            if(odd && currentOutputSize == n - 1 && (i == 2 || i == 4))
            {
                continue;
            }
            
            currentOutput.push_back(digits[i]);
            generateCombinations(n, i, odd, digits, limit, currentOutput, output);
            currentOutput.pop_back();
        }
    }
};