class Solution {
public:
    bool isPalindrome(string s, int l, int h)
    {
        if(l > h)
        {
            return false;
        }
        
        while(l < h)
        {
            if(s[l] != s[h])
            {
                return false;
            }
            
            l ++; 
            h --;
        }
        
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> output;
        if(s.size() == 0)
        {
            return output;
        }
        
        vector<string> currentOutput;
        
        generatePalindromeCombinations(s, 0, currentOutput, output);
        
        return output;
    }
    
    void generatePalindromeCombinations(string& s, int index, vector<string> currentOutput, vector<vector<string>>& output)
    {
        if(index == s.size())
        {
            output.push_back(currentOutput);
        }
        
        for(int i = index; i < s.size(); i ++)
        {
            if(isPalindrome(s, index, i))
            {
                currentOutput.push_back(s.substr(index, i - index + 1));
                generatePalindromeCombinations(s, i + 1, currentOutput, output);
                currentOutput.pop_back();
            }
        }
    }
};