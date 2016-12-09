class Solution {
public:
    int search(vector<int>& nums, int key, int lower)
    {
        int l = lower, u = nums.size() - 1;
        while(l <= u)
        {
            int mid = ((u - l) / 2) + l;
            int midElement = nums[mid];
            if(midElement == key)
            {
                return mid;
            }
            
            if(l == u)
            {
                return -1;
            }
            
            if(midElement < key)
            {
                l = mid + 1;
            }
            else
            {
                u = mid - 1;
            }
        }
        
        return -1;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int length = nums.size();
        vector<vector<int>> output;
        if(length < 3)
        {
            return output;
        }
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < length;)
        {
            int a = nums[i];
            for(int j = i + 1; j < length;)
            {
                int b = nums[j];
                
                int key = (-1) *(a + b);
                int keyIndex = search(nums, key, j + 1);
                
                if(keyIndex != -1)
                {
                    vector<int> result; 
                    result.push_back(nums[i]);
                    result.push_back(nums[j]);
                    result.push_back(nums[keyIndex]);
                    output.push_back(result);
                }
                
                while(j < length)
                {
                    if(nums[j] == b)
                    {
                        j ++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            
            while(i < length)
            {
                if(nums[i] == a)
                {
                    i ++;
                }
                else
                {
                    break;
                }
            }
        }
        
        return output;
    }
};