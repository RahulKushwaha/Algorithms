class Solution {
public:
    int lengthOfLastWord(string s) {
        size_t index = s.find_last_not_of(' ');
        
        if(index != string::npos)
        {
            s.erase(index + 1, s.size());    
        }
        
        int counter = 0;
        for(int i = s.size() - 1; i >= 0; i --)
        {
            if(s[i] == ' ')
            {
                break;
            }
            
            counter ++;
        }
        
        return counter;
    }
};