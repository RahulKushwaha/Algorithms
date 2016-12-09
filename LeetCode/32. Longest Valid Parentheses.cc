class Solution {
public:
    int longestValidParentheses(string s) {
        int length = s.size();
        if(length < 2)
        {
            return 0;
        }
        
        stack<int> elements;
        int ans = 0;
        
        for(int i = 0; i < length; i ++)
        {
            if(elements.empty() || s[i] == '(')
            {
                elements.push(i);
            }
            else
            {
                int top = elements.top();
                if(s[top] == '(')
                {
                    elements.pop();
                    
                    ans = max(ans, i - (elements.empty() ? -1 : elements.top()));
                }
                else
                {
                    elements.push(i);
                }
            }
        }
        
        return ans;
    }
};