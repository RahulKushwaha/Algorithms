class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string output;
        if(strs.size() == 0)
        {
            return output;
        }
        
        for(int j = 0; ; j ++)
        {
            char ch = '.';
            if(strs[0].size() > j)
            {
                ch = strs[0][j];
            }
            
            for(int i = 0; i < strs.size() ; i++)
            {
                if(strs[i].size() < j || strs[i][j] != ch)
                {
                    return output;
                }
            }
            
            output += ch;
        }
        
        return output;
        
    }
};