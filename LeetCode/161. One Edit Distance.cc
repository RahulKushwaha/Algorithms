class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int lengthS = s.size();
        int lengthT = t.size();
        
        for(int i = 0; i < lengthS && i < lengthT; i ++)
        {
            if(s[i] != t[i])
            {
                return s.substr(i + 1).compare(t.substr(i)) == 0 ||
                       s.substr(i + 1).compare(t.substr(i + 1)) == 0 ||
                       s.substr(i).compare(t.substr(i + 1)) == 0;
            }
        }
        
        return abs(lengthS - lengthT) == 1;
    }
};