class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int length = nums.size();
        
        if(length == 0 || length == 1)
        {
            return length;
        }
        
        unordered_set<int> elements;
        
        for(int i = 0; i < length; i ++)
        {
            elements.insert(nums[i]);
        }
        
        
        int output = 0;
        unordered_set<int>::iterator endMarker = elements.end();
        for(int i = 0; i < length; i ++)
        {
            unordered_set<int>::iterator itr = elements.find(nums[i] - 1);
            if(itr == endMarker)
            {
                int current = 0;
                for(int j = nums[i]; j <= INT_MAX; j ++)
                {
                    if(elements.find(j) != endMarker)
                    {
                        current ++;
                    }
                    else
                    {
                        break;
                    }
                }
                
                output = max(output, current);
            }
        }
        
        return output;
    }
};