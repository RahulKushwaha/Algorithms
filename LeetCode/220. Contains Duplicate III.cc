class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int length = nums.size();
        if(length <= 1 || k == 0)
        {
            return false;
        }
        
        set<int> numbers;
        
        for(int i = 0; i < length; i ++)
        {
            set<int>::iterator itr = numbers.lower_bound(nums[i] - t);
            if(itr != numbers.end())
            {
                if(abs(*itr - nums[i]) <= t)
                {
                    return true;
                }
            }
            
            itr = numbers.upper_bound(nums[i]);
            if(itr != numbers.end())
            {
                if(abs(*itr - nums[i]) <= t)
                {
                    return true;
                }
            }
            
            numbers.insert(nums[i]);
            if(numbers.size() > k)
            {
                numbers.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};