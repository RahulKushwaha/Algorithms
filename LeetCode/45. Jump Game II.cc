class Solution {
public:
    int jump(vector<int>& nums) {
        int length = nums.size();
        if(length == 0)
        {
            return 0;
        }
        
        if(length == 1)
        {
            return 0;
        }
        
        int range = nums[0];
        int steps = 1;
        int * input = &nums[0];
        for(int i = 1; i <= range;)
        {
            if(range >= length - 1)
            {
                break;
            }
            
            int maxRange = INT_MIN;
            int maxIndex;
            for(int j = i; j <= range && j < length; j++)
            {
                int currentRange = input[j] + j;
                if(currentRange > maxRange)
                {
                    maxRange = currentRange;
                    maxIndex = j;
                }
            }
            
            i = maxIndex;
            range = maxRange;
            steps++;
        }
        
        return steps;
    }
};