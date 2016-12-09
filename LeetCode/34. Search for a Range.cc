class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> output;
        if(nums.size() <= 0)
        {
            output.push_back(-1);
            output.push_back(-1);
        }
        
        int start = -1, end = -1, l = 0, u = nums.size() - 1;
        
        while(l <= u)
        {
            int mid = ((u - l) / 2) + l;
            if(nums[mid] == target)
            {
                start = mid;
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
            else
            {
                u = mid - 1;
            }
        }
        
        l = 0; 
        u = nums.size() - 1;
        
        while(l <= u)
        {
            int mid = ((u - l) / 2) + l;
            if(nums[mid] == target)
            {
                end = mid;
                if(l == u)
                {
                    break;
                }
                
                l = mid + 1;
            }
            else if(nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                u = mid - 1;
            }
        }
        
        output.push_back(start);
        output.push_back(end);
        
        return output;
    }
};