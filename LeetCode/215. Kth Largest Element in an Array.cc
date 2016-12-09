class Solution {
public:

    int partition(vector<int>& arr, int left, int right)
    {
        int l = left - 1;
        int x = arr[right];
        for(int i = left; i < right; i ++)
        {
            if(arr[i] < x)
            {
                l ++;
                swap(arr[l], arr[i]);
            }
        }
        
        l++;
        swap(arr[l], arr[right]);
        
        return l;
    }
    
    int findKthLargest(vector<int>& nums, int k)
    {
        int length = nums.size();
        k = length - k;
    
        int l = 0;
        int u = length - 1;
    
        int partitionIndex = partition(nums, 0, length - 1);
    
        while(partitionIndex != k)
        {
            if(k < partitionIndex)
            {
                u = partitionIndex - 1;
            }
            else
            {
                l = partitionIndex + 1;
            }
    
            partitionIndex = partition(nums, l, u);
        }
    
        return nums[k];
    }
};