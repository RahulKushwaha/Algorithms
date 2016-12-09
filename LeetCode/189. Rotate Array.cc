class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        k %= length;
        
        if(k == 0 || length == 0)
        {
            return ;
        }
        
        int pivot = length - k;
        
        //Reverse the digits in the input;
        reverse(nums.begin(), nums.end());
        
        reverse(nums.begin(), nums.begin() + (k - 1));
        
        reverse(nums.begin() + k, nums.end());
    }
};