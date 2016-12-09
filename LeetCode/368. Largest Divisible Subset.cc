class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int length = nums.size();
        
        if(length <= 1)
        {
            return nums;
        }
        
        sort(nums.begin(), nums.end());
        int dp[length];
        vector<int> ansSet;
        ansSet.resize(length);
        
        int ans = 0;
        int maxIndex = 0;
        for(int i = 0; i < length; i ++)
        {
            int factors = 1;
            ansSet[i] = i;
            
            int index = i;
            for(int j = 0; j < i; j ++)
            {
                if(nums[i] % nums[j] == 0)
                {
                    if(factors < dp[j] + 1)
                    {
                        factors = dp[j] + 1;
                        index = j;
                    }
                }
            }
            
            if(index != i)
            {
                ansSet[i] = index;
            }
            
            dp[i] = factors;
            if(ans < dp[i])
            {
                maxIndex = i;
                ans = dp[i];
            }
        }
        
    
        vector<int> output;
        while(ansSet[maxIndex] != maxIndex)
        {
            output.push_back(nums[maxIndex]);
            maxIndex = ansSet[maxIndex];
        }
        
        output.push_back(nums[ansSet[maxIndex]]);
        reverse(output.begin(), output.end());
        
        return output;
    }
};