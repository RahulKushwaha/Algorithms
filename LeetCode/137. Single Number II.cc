class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int result = 0;
        
        for(int a = 0; a < 32; a ++)
        {
            int count = 0;
            int x = 1<< a;
            for(int i = 0; i < nums.size(); i ++)
            {
                int num = nums[i];
                if(num & 1 == 1)
                {
                    // Collect the number of times the designated bit is ON.
                    count ++;
                }
                
                // Extract the last bit of the Number.
                nums[i] = num>>1;
            } 
            
            // If this particular bit is ON in multiple of 3 then it must not belong to the only single number that is present.
            if(count % 3)
            {
                result |= x;
            }
        }
        
        return result;
    }
};