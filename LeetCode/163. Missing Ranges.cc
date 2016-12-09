class Solution {
public:

    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int length = nums.size();
        vector<string> output;
        
        if(length == 0)
        {
            if(lower == upper)
            {
                output.push_back(to_string(lower));
            }
            else
            {
                output.push_back(to_string(lower) + "->" + to_string(upper));
            }
            
            return output;
        }
        
        if(nums[0] != lower)
        {
            nums.insert(nums.begin(), lower - 1);
            length ++;
        }
        
        if(nums[length - 1] != upper)
        {
            nums.push_back(upper + 1);
            length ++;
        }

        int last = nums[0];
        for(int i = 1; i < length; i ++)
        {
            if(nums[i] - last >= 2)
            {
                if(nums[i] - last == 2)
                {
                    output.push_back(to_string(last + 1));
                }
                else
                {
                    output.push_back(to_string(last + 1) + "->" + to_string(nums[i] - 1));
                }
            }
            
            last = nums[i];
        }
        
        return output;
    }
};