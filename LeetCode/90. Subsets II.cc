class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> output;
        
        int length = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> currentOutput;
        subsets(nums, 0, length, currentOutput, output);
        return output;
    }
    
    void subsets(vector<int>& nums, int index, int& length, vector<int>& currentOutput, vector<vector<int>>& output)
    {
        output.push_back(currentOutput);
        if(index == length)
        {
            return;
        }
        
        for(int i = index; i < nums.size(); )
        {
            currentOutput.push_back(nums[i]);
            subsets(nums, i + 1, length, currentOutput, output);
            currentOutput.pop_back();
            
            int a = nums[i];
            while(i < nums.size() && nums[i] == a)
            {
                i ++;
            }
        }
    }
};