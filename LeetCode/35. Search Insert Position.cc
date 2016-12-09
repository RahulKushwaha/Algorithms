class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() <= 0)
        {
            return 0;
        }
        
        int l = -1, u = nums.size() - 1;
        int position = -1;
        while(l <= u)
        {
            int mid = ((u - l) / 2) + l;
            
            if(nums[mid] >= target)
            {
                position = mid;
                if(l == u)
                {
                    break;
                }
                
                u = mid - 1;
            }
            else if(nums[mid] < target)
            {
                l = mid + 1;
            }
        }
        
        return position == -1 ? (target < nums[0] ? 0 : nums.size()) : position;
    }
};