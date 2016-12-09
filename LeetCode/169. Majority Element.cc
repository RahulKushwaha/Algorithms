class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int size = nums.size();
        pair<int, int> majorityCandidate;
        majorityCandidate.first = nums[0]; 
        majorityCandidate.second = 1;
        for(int i = 1; i < nums.size(); i ++)
        {
            if(majorityCandidate.first == nums[i])
            {
                majorityCandidate.second ++;
            }
            else
            {
                majorityCandidate.second --;
                if(majorityCandidate.second == 0)
                {
                    majorityCandidate.first = nums[i];
                    majorityCandidate.second = 1;
                }
            }
        }
        
        int count = 0;
        
        for(int i = 0; i < nums.size(); i ++)
        {
            if(nums[i] == majorityCandidate.first)
            {
                count++;
            }
        }
        
        return majorityCandidate.first;
    }
};