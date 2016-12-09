class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> output;
        int length = num.size();
        
        for(int i = 0; i < length; i ++)
        {
            long currentNum = stol(num.substr(0, i + 1));
            addOperators(num, i + 1, target, currentNum, '#', currentNum, to_string(currentNum), output);
            
            if(currentNum == 0)
            {
                break;
            }
        }
        
        return output;
    }
    
    void addOperators(string& num,
                      int index,
                      int target,
                      long currentSum,
                      char prevOp,
                      long prevVal,
                      string currentOutput, 
                      vector<string>& output)
    {
        if(index == num.size())
        {
            if(target == currentSum)
            {
                output.push_back(currentOutput);
            }
            
            return;
        }
        
        for(int i = index; i < num.size(); i ++)
        {
            long currentNum = stol(num.substr(index, i - index + 1));
            
            if(prevOp == '+')
            {
                addOperators(num, i + 1, target, currentSum - prevVal + prevVal * currentNum, prevOp, prevVal * currentNum, currentOutput + '*' + to_string(currentNum), output);
            }
            else if(prevOp == '-')
            {
                addOperators(num, i + 1, target, currentSum + prevVal - prevVal * currentNum, prevOp, prevVal * currentNum, currentOutput + '*' + to_string(currentNum), output);
            }
            else 
            {
                addOperators(num, i + 1, target, currentSum * currentNum, prevOp, prevVal * currentNum, currentOutput + '*' + to_string(currentNum), output);
            }
            
            addOperators(num, i + 1, target, currentSum + currentNum, '+', currentNum, currentOutput + '+' + to_string(currentNum), output);
            
            addOperators(num, i + 1, target, currentSum - currentNum, '-', currentNum, currentOutput + '-' + to_string(currentNum), output);
            
            if(currentNum == 0)
            {
                break;
            }
        }
    }
};