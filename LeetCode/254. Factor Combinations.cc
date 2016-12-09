class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> output;
        if(n <= 1)
        {
            return output;
        }
        
        vector<int> factors;
        
        getFactors(2, sqrt(n), n, 1, factors, output);
        
        return output;
    }
    
    void getFactors(int index,
                    int limit,
                    int n,
                    int currentProduct,
                    vector<int>& factors,
                    vector<vector<int>>& output)
    {
        if(currentProduct > n)
        {
            return;
        }
        
        for(int i = index; i <= limit; i ++)
        {
            if(n %(currentProduct * i) == 0)
            {
                factors.push_back(i);
                int factor = n/(currentProduct*i);
                if(factor >= i)
                {
                    factors.push_back(factor);
                    output.push_back(factors);
                    factors.pop_back();
                }
                
                getFactors(i, limit, n, currentProduct * i, factors, output);
                factors.pop_back();
            }
        }
    }
};