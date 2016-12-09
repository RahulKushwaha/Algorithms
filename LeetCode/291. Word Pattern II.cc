class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        int plength = pattern.size();
        int slength = str.size();
        
        if(plength == 0 && slength == 0)
        {
            return true;
        }
        
        if(plength == 0 || slength == 0)
        {
            return false;
        }
        
        return wordPatternMatch(pattern, str, plength, slength, 0, 0);
    }
    
    unordered_map<char, string> lookup;
    unordered_set<string> visited;
    
    bool wordPatternMatch(string& pattern, string& str, int plength, int slength, int pindex, int sindex)
    {
        
        if(pindex == plength && sindex == slength)
        {
            return true;
        }
        
        if(pindex >= plength || sindex >= slength)
        {
            return false;
        }
        
        bool flag = false;
        
        for(int i = sindex; i < slength; i ++)
        {
            char ch = pattern[pindex];
            unordered_map<char, string>::iterator itr = lookup.find(ch);
            string temp = str.substr(sindex, i - sindex + 1);
            
            if(itr == lookup.end())
            {
                if(visited.find(temp) != visited.end())
                {
                    flag |= false;
                    continue;
                }
                
                lookup[ch] = temp;
                visited.insert(temp);
                
                flag |= wordPatternMatch(pattern, str, plength, slength, pindex + 1, i + 1);
                
                lookup.erase(ch);
                visited.erase(temp);
            }
            else
            {
                if(itr->second.compare(temp) == 0)
                {
                    flag |= wordPatternMatch(pattern, str, plength, slength, pindex + 1, i + 1);
                }
            }
        }
        
        return flag;
    }
};