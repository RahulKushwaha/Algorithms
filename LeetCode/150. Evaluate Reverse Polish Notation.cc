class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<string> polish;
        
        for(int i = 0; i < tokens.size(); i ++)
        {
            string currentToken = tokens[i];
            if(currentToken == "*" ||
               currentToken == "+" ||
               currentToken == "-" ||
               currentToken == "/")
               {
                   int a = stoi(polish.top());
                   polish.pop();
                   int b = stoi(polish.top());
                   polish.pop();
                   
                   int result;
                   
                   switch(currentToken[0])
                   {
                       case '*':
                       result = a * b;
                       break;
                       
                       case '+':
                       result = a + b;
                       break;
                       
                       case '-':
                       result = b - a;
                       break;
                       
                       case '/':
                       result = b / a;
                       break;
                   }
                   
                   polish.push(to_string(result));
               }
               else
               {
                   polish.push(currentToken);
               }
        }
        
        return stoi(polish.top());
    }
};