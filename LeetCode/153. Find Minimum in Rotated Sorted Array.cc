class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = INT_MAX;

        findMin(nums, 0, nums.size() -1 , min);
        
        return min;
    }
    
    void findMin(vector<int>& nums, int l, int h, int& min)
    {
        if(l > h){
            return;
        }
        
        if(l == h){
            min = nums[h];
            return;
        }
        
        if(h - l == 1){
            min = nums[l] < nums[h] ? nums[l] : nums[h];
            return;
        }
        
        int mid = ((h - l) / 2) + l;
        
        if(nums[l] <= nums[h]){
            if(min > nums[l]){
                min = nums[l];
            }
            
            return;
        }
        
        if(nums[l] <= nums[mid]){
            findMin(nums, mid, h, min);
        }
        else{
            findMin(nums, l, mid, min);
        }
    }
};