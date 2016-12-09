class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> output; 
        
        if(n == 0 || k == 0 || k > n)
        {
            return output;
        }
        
        vector<int> current; 
        
        combine(k, 1, n, current, output);
        
        return output;
    }
    
    void combine(int k, int index, int n, vector<int>& current, vector<vector<int>>& output)
    {
        if(current.size() > k)
        {
            return;
        }
        
        if(current.size() == k)
        {
            output.push_back(current);
            return;
        }
        
        for(int i = index; i <= n; i ++)
        {
            current.push_back(i);
            combine(k, i + 1, n, current, output);
            current.pop_back();
        }
    }
};