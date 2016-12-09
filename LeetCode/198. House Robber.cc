class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        int lastVal = 0; 
        int secondLastVal = 0;
        
        for(int i = 0; i < size; i ++)
        {
            int current = lastVal > secondLastVal + nums[i] ? lastVal : secondLastVal + nums[i];
            secondLastVal = lastVal;
            lastVal = current;
        }
        
        return lastVal;
    }
};