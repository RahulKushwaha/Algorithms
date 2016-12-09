class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int length = envelopes.size();
        if(length == 0)
        {
            return 0;
        }
        
        sort(envelopes.begin(), envelopes.end());
        
        int dp[length] = {0};
        for(int i = 0; i < length; i ++)
        {
            dp[i] = 1;
        }
        
        int ans = 0;
        
        for(int i = 0; i < length; i ++)
        {
            pair<int, int> parent = envelopes[i];
            int num = 1;
            for(int j = 0; j < i; j ++)
            {
                pair<int, int> child = envelopes[j];
                
                if(parent.first > child.first &&
                   parent.second > child.second)
                {
                    num = max(num, dp[j] + 1);
                }
            }
            
            dp[i] = num;
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};