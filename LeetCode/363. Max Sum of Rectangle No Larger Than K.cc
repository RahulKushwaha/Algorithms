class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        if(rows == 0)
        {
            return 0;
        }
        
        int cols = matrix[rows - 1].size();
        
        if(cols == 0)
        {
            return 0;
        }
        
        int ans = INT_MIN;
        
        int dp[rows];
        for(int i = 0; i < cols; i ++)
        {
            for(int r = 0; r < rows; r ++)
            {
                dp[r] = 0;
            }
            
            for(int j = i; j < cols; j ++)
            {
                for(int r = 0; r < rows; r ++)
                {
                    dp[r] += matrix[r][j];
                }
                
                ans = max(ans, maxSubArrayLen(dp, k, rows));
            }
        }
        
        return ans;
    }
    
    int maxSubArrayLen(int* nums, int k, int length) {
        set<int> lookup;
        
        int currentSum = 0;
        int ans = INT_MIN;
        
        for(int i = 0; i < length; i ++)
        {
            currentSum += nums[i];
            if(currentSum <= k)
            {
                ans = max(ans, currentSum);
            }
            
            set<int>::iterator itr = lookup.lower_bound(currentSum - k);
            if(itr != lookup.end())
            {
                ans = max(ans, currentSum - *itr);
            }
            
            lookup.insert(currentSum);
        }
        
        return ans;
    }
};