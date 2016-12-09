class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int length = nums.size();
        
        int sum = 0;
        long long currentMax = 0;
        int patchesRequired = 0;
        
        for(int i = 0; currentMax < n;)
        {
            if(i < length && nums[i] <= currentMax + 1)
            {
                currentMax += nums[i ++];
            }
            else
            {
                patchesRequired ++;
                currentMax = (currentMax << 1) + 1; 
            }
        }
        
        return patchesRequired;
    }
};