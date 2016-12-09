class Solution {
public:
    string parseTernary(string expression) {
        int length = expression.size();
        if(length == 0)
        {
            return "";
        }
        
        stack<char> elements;
        
        for(int i = length - 1; i >= 0; i --)
        {
            char ch = expression[i];
            if(ch == ':')
            {
                
            }
            else if(ch == '?')
            {
                i --;
                bool condition = expression[i] == 'T' ? true : false;
                char a = elements.top();
                elements.pop();
                char b = elements.top();
                elements.pop();
                
                if(condition)
                {
                    elements.push(a);
                }
                else
                {
                    elements.push(b);
                }
            }
            else
            {
                elements.push(ch);
            }
        }

        stringstream ss;
        ss<<elements.top();
        return ss.str();
    }
};