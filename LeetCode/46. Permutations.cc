class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output; 
        
        if(nums.size() == 0)
        {
            return output;    
        }
        
        bool * visited = new bool[nums.size()];
        for(int i = 0;i < nums.size(); i ++)
        {
            visited[i] = false;
        }
        
        vector<int> currentOutput;
        permute(nums, visited, currentOutput, output);
        return output;
    }
    
    void permute(vector<int>& nums, bool * visited, vector<int>& currentOutput, vector<vector<int>>& outputs)
    {
        if(currentOutput.size() == nums.size())
        {
            outputs.push_back(currentOutput);
            return;
        }
        
        for(int i = 0; i < nums.size(); i ++)
        {
            if(visited[i] == false)
            {
                visited[i] = true;
                currentOutput.push_back(nums[i]);
                
                permute(nums, visited, currentOutput, outputs);
                
                currentOutput.pop_back();
                visited[i] = false;
            }
        }
    }
};