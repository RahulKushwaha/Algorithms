class Solution {
public:
    int numSquares(int n) {
        if(n <= 0)
        {
            return 0;
        }
        
        vector<int> lookup;
        lookup.resize(n + 1);
        
        lookup[0] = 0;
        lookup[1] = 1;
        
        vector<int> candidates;
        for(int i = sqrt(n); i >= 1; i --)
        {
            candidates.push_back(i * i);
        }
        
        for(int i = 2; i <= n; i ++)
        {
            int min = INT_MAX;
            for(int j = candidates.size() - 1; j >= 0; j --)
            {
                int current = i - candidates[j];
                if(current >= 0 && lookup[current] != INT_MAX)
                {
                    int currentSquare = lookup[current] + 1;
                    if(currentSquare < min)
                    {
                        min = currentSquare;
                    }
                }
            }
            
            lookup[i] = min;
        }
        
        return lookup[n] == UINT_MAX ? - 1 : lookup[n];
    }
};