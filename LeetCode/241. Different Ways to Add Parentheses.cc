class Solution {
public:
    unordered_map<string, vector<int>> lookup;
    
    vector<int> diffWaysToCompute(string input)
    {
        vector<int> output; 
        
        int length = input.size();
        if(length ==  0)
        {
            return output;
        }
        
        unordered_map<string, vector<int>>::iterator itr = lookup.find(input);
        if(itr != lookup.end())
        {
            return itr->second;
        }
        
        int num = 0;
        for(int i = 0;; i ++)
        {
            if(i == length)
            {
                output.push_back(num);
                return output;
            }
            
            if(input[i] - '0' < 0 || input[i] - '0' > 9)
            {
                break;
            }
            
            num *= 10;
            num += (input[i] - '0');
        }
        
        for(int i = 0; i < length; i ++)
        {
            if(isdigit(input[i]) == false)
            {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                
                if(left.size() == 0)
                {
                    return right;
                }
                
                if(right.size() == 0)
                {
                    return left;
                }
                
                for(int a = 0; a < left.size(); a ++)
                {
                    for(int b = 0; b < right.size(); b ++)
                    {
                        int result;
                        switch(input[i])
                        {
                            case '+':
                            result = left[a] + right[b];
                            break;
                            
                            case '-':
                            result = left[a] - right[b];
                            break;
                            
                            case '*':
                            result = left[a] * right[b];
                            break;
                        }
                        
                        output.push_back(result);
                    }
                }
            }
        }
        
        //sort(output.begin(), output.end());
        
        lookup.insert(pair<string, vector<int>>(input, output));
        
        return output;
    }
};