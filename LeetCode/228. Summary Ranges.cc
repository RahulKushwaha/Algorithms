class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> output;
        if(nums.size() == 0)
        {
            return output;
        }
        
        //start & end are indices.
        int start = 0;
        int end = 0;
        for(int i = 1;;)
        {
            if(i != nums.size() && nums[i] - nums[i - 1] == 1)
            {
                end = i++;
            }
            else
            {
                string range;
                if(start == end)
                {
                    range = to_string(nums[end]);
                }
                else
                {
                    range = to_string(nums[start]) + "->" + to_string(nums[end]);
                }
                
                output.push_back(range);
                
                start = end = i;

                if(i == nums.size())
                {
                    break;
                }
                
                i ++;
            }
        }
        
        return output;
    }
};