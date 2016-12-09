class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> output;
        if(candidates.size() == 0)
        {
            return output;
        }
        
        vector<int> currentOutput;
        
        combinations(output, currentOutput, candidates, 0, 0, target);
        
        return output;
    }
    
    void combinations(vector<vector<int>>& output,
                      vector<int>& currentOutput,
                      vector<int>& candidates,
                      int currentIndex,
                      int sum,
                      int n)
    {
        if(sum > n)
        {
            return;
        }
        
        if(sum == n)
        {
            output.push_back(currentOutput);
            return;
        }
        
        for(int i = currentIndex; i < candidates.size(); i ++)
        {
            currentOutput.push_back(candidates[i]);
            combinations(output, currentOutput, candidates, i, sum + candidates[i], n);
            currentOutput.pop_back();
        }
    }
};