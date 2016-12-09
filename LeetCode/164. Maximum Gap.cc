class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int length = nums.size();
        if(length == 0 || length == 1)
        {
            return 0;
        }
        
        vector<int> output;
        output.resize(length);
        for(int i = 0; i < 4; i ++)
        {
            unsigned freq[256] = {0};
            int offset = i * 8;
            
            for(int j = 0; j < length; j ++)
            {
                int index = 0x000000ff;
                index = (nums[j]>>offset) &index;
                freq[index] ++;
            }
            
            for(int j = 1; j < 256; j ++)
            {
                freq[j] += freq[j - 1];
            }
            
            for(int j = length - 1; j >= 0; j --)
            {
                int index = 0x000000ff;
                index = (nums[j]>>offset) &index;
                freq[index]--;
                output[freq[index]] = nums[j];
            }
            
            for(int j = 0; j < length; j ++)
            {
                nums[j] = output[j];
            }
        }
        
        int maxGap = 0;
        for(int i = 1; i < length; i ++)
        {
            int gap = nums[i] - nums[i - 1];
            if(gap > maxGap)
            {
                maxGap = gap;
            }
        }
        
        return maxGap;
    }
};