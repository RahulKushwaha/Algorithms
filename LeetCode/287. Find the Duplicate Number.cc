class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int length = nums.size();
        
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        }

        slow = 0;
        
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};