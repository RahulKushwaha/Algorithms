class Solution {
public:
    vector<int> subsetElements(int n)
    {
        vector<int> subset;
        int counter = 0;
        while(n != 0)
        {
            int temp = n % 2;
            if(temp == 1)
            {
                subset.push_back(counter);
            }
            
            n /= 2;
            counter ++;
        }
        
        return subset;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        int limit = 1 << nums.size();
        for(int i = 0; i < limit; i ++)
        {
            vector<int> subset = subsetElements(i);
            vector<int> set;
            for(int j = 0; j < subset.size(); j ++)
            {
                set.push_back(nums[subset[j]]);
            }
            
            output.push_back(set);
        }
        
        return output;
    }
};