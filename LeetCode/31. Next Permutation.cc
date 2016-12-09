class Solution {
public:
    void swap(int &a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    
    void Reverse(vector<int>& nums, int i, int j)
    {
        while(i < j)
        {
            swap(nums[i], nums[j]);
            i ++;
            j --;
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        
        if(nums.size() == 0 || nums.size() == 1)
        {
            return;
        }
        
        int increasingSuffixIndex = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 0; i --)
        {
            if(nums[i] >= nums[increasingSuffixIndex])
            {
                increasingSuffixIndex = i;
            }
            else
            {
                break;
            }
        }
        
        if(increasingSuffixIndex == 0)
        {
            Reverse(nums, 0, nums.size() - 1);
            
            return;
        }
        
        int pivotIndex = increasingSuffixIndex - 1;
        int swapIndex = increasingSuffixIndex;
        
        for(int i = increasingSuffixIndex; i < nums.size(); i ++)
        {
            if(nums[i] > nums[pivotIndex])
            {
                swapIndex = i;
            }
        }
        
        swap(nums[swapIndex], nums[pivotIndex]);
        
        Reverse(nums, pivotIndex + 1, nums.size() - 1);
        
    }
};