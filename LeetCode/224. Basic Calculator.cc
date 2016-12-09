class Solution {
public:

    int getNum(string& s, int startIndex, int& endIndex)
    {
        int num = 0; 
        int multiplier = 1;
        int i = startIndex;
        
        for(; i < s.size() && isdigit(s[i]); i ++)
        {
            num *= 10;
            num += s[i] - '0';
        }
        
        endIndex = i;
        //cout<<"Error in GetNuM"<<num<<endl;
        
        return num;
    }
    
    int eval(int a, int b, char o)
    {
        switch(o)
        {
            case '+':
            return a + b; 
            
            case '-': 
            return a - b;
            
            case '*':
            return a * b;
            
            case '/': 
            return a/b;
        }
        
        return 0;
    }
    
    int calculate(string s) {
        stack<char> operands; 
        stack<int> nums;
        map<char, int> operandsRank;
        operandsRank.insert(pair<char, int>('*', 3));
        operandsRank.insert(pair<char, int>('/', 3));
        operandsRank.insert(pair<char, int>('+', 2));
        operandsRank.insert(pair<char, int>('-', 2));
        
        string postfix;
        
        for(int i = 0; i < s.size();)
        {
            switch(s[i])
            {
                case ' ': 
                i ++;
                break;
                
                case '+':
                case '-': 
                case '*':
                case '/':
                case '(':
                case ')':
                if(operands.empty() || s[i] == '(')
                {
                    operands.push(s[i]);
                }
                else
                {
                    while(operands.empty() != true && operands.top() != '(')
                    {
                        if(operandsRank[s[i]] <= operandsRank[operands.top()])
                        {
                            int b = nums.top();
                            nums.pop();
                            int a = nums.top();
                            nums.pop();
                            
                            int c = eval(a, b, operands.top());
                            nums.push(c);
                            operands.pop();
                        }
                        else{
                            break;
                        }
                    }
                    
                    if(s[i] == ')')
                    {
                        operands.pop();
                    }
                    else{
                       operands.push(s[i]); 
                    }
                }
                
                i ++;
                break;
                
                default:
                int num = getNum(s, i, i);
                nums.push(num);
                break;
            }
        }

        while(operands.empty() == false)
        {
            int b = nums.top();
            nums.pop();
            int a = nums.top();
            nums.pop();
            
            int c = eval(a, b, operands.top());
            nums.push(c);
            
            operands.pop();
        }

        return nums.top();
    }
};