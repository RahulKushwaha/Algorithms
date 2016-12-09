class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        
        int output = 0;
        for(int i = s.size() - 1, j = g.size() - 1; i >= 0 && j >= 0;)
        {
            if(g[j] > s[i])
            {
                j --;
            }
            else
            {
                i --; 
                j --;
                output ++;
            }
        }
        
        return output;
    }
};