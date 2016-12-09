class Solution {
public:
    void buildFailure(string & p, vector<int>& f)
    {
        f[0] = 0;
        int j = 0;
        
        for(int i = 1; i < p.size(); i ++)
        {
            while(j > 0 && p[i] != p[j])
            {
                j = f[j - 1];
            }
            
            if(p[j] == p[i])
            {
                j ++;
            }
            
            f[i] = j;
        }
    }
    
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
        {
            return 0;
        }
        
        if(haystack.size() == 0)
        {
            return -1;
        }
        
        vector<int> f;
        f.resize(needle.size());
        
        buildFailure(needle, f);
        
        int j = 0;
        int i = 0;
        for(; ;)
        {
            if(j == needle.size())
            {
                return i - needle.size();
            } 
            
            if(i == haystack.size())
            {
                break;
            }
            
            if(needle[j] == haystack[i])
            {
                j ++;
                i ++;
            }
            else if(j > 0)
            {
                j = f[j - 1];
            }
            else
            {
                i ++;
            }
        }
        
        return -1;
    }
};