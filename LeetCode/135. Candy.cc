class Solution {
public:
    int candy(vector<int>& ratings) {
        int length = ratings.size();
        
        if(length == 0)
        {
            return 0;
        }
        
        int output[length];
        
        for(int i = 0; i < length ; i ++)
        {
            output[i] = 1;
        }
        
        int* input = &ratings[0];
        
        for(int i = 1; i < length; i ++)
        {
            if(input[i] > input[i - 1])
            {
                output[i] = output[i - 1] + 1;
            }
        }
        
        for(int i = length - 2; i >= 0; i --)
        {
            if(input[i] > input[i + 1] && output[i] <= output[i + 1])
            {
                output[i] = output[i + 1] + 1;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < length; i ++)
        {
            ans += output[i];
        }
        
        return ans;
    }
};