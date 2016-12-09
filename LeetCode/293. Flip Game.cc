class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> output;
        int length = s.size();
        if(length == 0)
        {
            return output;
        }
        
        for(int i = 1; i < length; i ++)
        {
            if(s[i] == '+' && s[i] == s[i - 1])
            {
                s[i - 1] = s[i] = '-';
                output.push_back(s);
                s[i - 1] = s[i] = '+';
            }
        }
        
        return output;
    }
};