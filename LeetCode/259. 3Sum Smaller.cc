int search(int * nums, int l, int u, int key)
{
    int total = 0;
    while(l < u)
    {
        int sum = nums[l] + nums[u];
        if(sum < key)
        {
            // The number of elements that can be combined with nums[l] which produce a sum < key.
            total += (u - l);
            l ++;
        }
        else
        {
            u --;
        }
    }
    
    return total;
}
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int length = nums.size();
        if(length == 0)
        {
            return 0;
        }
        
        int* arr = &nums[0];
        
        sort(arr, arr + length);
        
        int total = 0;
        for(int i = 0; i < length; i++)
        {
            int key = target - arr[i];
            total += search(arr, i + 1, length - 1, key);
        }
        
        return total;
    }
};