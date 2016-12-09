class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        if(n == 0)
        {
            return output;
        }
        
        generateParenthesis("", n * 2, 0, 0, output);
        
        return output;
    }
    
    void generateParenthesis(string currentOutput, int n, int left, int right, vector<string>& output)
    {
        if(left + right == n)
        {
            output.push_back(currentOutput);
            return;
        }
         
        if(left < n / 2)
        {
            generateParenthesis(currentOutput + '(', n, left + 1, right, output);
        }
        
        if(right < left)
        {
            generateParenthesis(currentOutput + ')', n, left, right + 1, output);
        }
    }
};