class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
        {
            return -1;
        }
        
        return search(nums, target, 0, nums.size() - 1);
    }
    
    int search(vector<int>& nums, int target, int l, int h)
    {
        if(l > h)
        {
            return - 1;
        }
        
        int mid = ((h - l) / 2) + l;
        
        if(nums[l] <= nums[mid] && nums[mid] <= nums[h])
        {
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                return search(nums, target, mid + 1, h);
            }
            else
            {
                return search(nums, target, l, mid - 1);
            }
        }
        
        if(nums[l] <= nums[mid])
        {
            if(target <= nums[mid] && target >= nums[l])
            {
                return search(nums, target, l, mid);
            }
            else
            {
                return search(nums, target, mid + 1, h);
            }
        }
        else if(nums[mid] <= nums[h])
        {
            if(target <= nums[h] && target >= nums[mid])
            {
                return search(nums, target, mid, h);
            }
            else
            {
                return search(nums, target, l, mid - 1);
            }
        }
        
        return -1;
    }
};