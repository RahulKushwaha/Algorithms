class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0)
        {
            return false;
        }
        
        if(nums.size() == 1)
        {
            return nums[0] == target;
        }
        
        return search(nums, 0, nums.size() - 1, target);
    }
    
    bool search(vector<int>& nums, int l, int h, int target)
    {
        if(l > h)
        {
            return false;
        }
        
        while(l < h)
        {
            if(nums[l] == nums[h])
            {
                h--;
            }
            else
            {
                break;
            }
        }

        if(l == h)
        {
            return nums[l] == target;
        }
        
        int mid = ((h - l) / 2) + l;
        
        if(nums[l] <= nums[mid] && nums[mid] <= nums[h])
        {
            if(nums[mid] == target)
            {
                return true;
            }
            else if(nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
            
            return search(nums, l, h, target);
        }
        
        if(nums[l] <= nums[mid])
        {
            if(target <= nums[mid] && nums[l] <= target)
            {
                return search(nums, l, mid, target);
            }
            
            return search(nums, mid + 1, h, target);
        }
        
        if(nums[mid] <= nums[h])
        {
            if(target >= nums[mid] && target <= nums[h])
            {
                return search(nums, mid, h, target);
            }
            
            return search(nums, l, mid - 1, target);
        }
        
        return false;
    }
};