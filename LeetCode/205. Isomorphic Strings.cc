class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.size() == 0 && t.size() == 0)
        {
            return true;
        }
        
        if(s.size() == 0 || t.size() == 0)
        {
            return false;
        }
        
        unordered_map<char, char> mapping;
        unordered_map<char, char> reverseMapping;
        
        int i = 0;
        for(; i < s.size() && i < t.size(); i ++)
        {
            unordered_map<char, char>::iterator itr = mapping.find(s[i]);
            if(itr != mapping.end())
            {
                if(itr->second != t[i])
                {
                    return false;
                }
            }
            else
            {
                mapping[s[i]] = t[i];
            }
        }
        
        for(unordered_map<char, char>::iterator itr = mapping.begin(); itr != mapping.end(); itr ++)
        {
            unordered_map<char, char>::iterator i = reverseMapping.find(itr->second);
            if(i == reverseMapping.end())
            {
                reverseMapping[itr->second] = itr->first;
            }
            else
            {
                if(i->second != itr->second)
                {
                    return false;
                }
            }
        }
        
        if(s.size() > t.size())
        {
            return true;
        }
        
        for(; i < t.size(); i ++)
        {
            if(mapping.find(t[i]) == mapping.end())
            {
                return false;
            }
        }
        
        return true;
    }
};