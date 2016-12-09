class Solution {
public:

    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> elements;

        removeInvalidParenthesis(s, 0, 0, 0, "", elements);
        
        vector<string> output;
        for(unordered_set<string>::iterator itr = elements.begin(); itr != elements.end(); itr ++)
        {
            output.push_back(*itr);
        }
        
        return output;
    }
    
    int maxLength = 0;
    void removeInvalidParenthesis(string& s, int index, int left, int right, string currentOutput, unordered_set<string>& output)
    {
        if(right > left)
        {
            return;
        }
        
        if(index == s.size() && right == left)
        {
            if(currentOutput.size() > maxLength)
            {
                output.clear();
                maxLength = currentOutput.size();
            }
            else if(currentOutput.size() < maxLength)
            {
                return;
            }
            
            output.insert(currentOutput);
        }
        
        if(index >= s.size())
        {
            return;
        }
        
        if(isalpha(s[index]))
        {
            removeInvalidParenthesis(s, index + 1, left, right, currentOutput + s[index], output);
        }
        else
        {
            if(s[index] == '(')
            {
                removeInvalidParenthesis(s, index + 1, left + 1, right, currentOutput + '(', output);
            }
            else if(s[index] == ')')
            {
                removeInvalidParenthesis(s, index + 1, left, right + 1, currentOutput + ')', output);
            }
            
            removeInvalidParenthesis(s, index + 1, left, right, currentOutput, output);
        }
    }
};