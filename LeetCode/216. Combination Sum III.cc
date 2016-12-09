class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> output; 
        if(k == 0)
        {
            return output;
        }
        
        vector<int> currentOutput;
        combinations(output, currentOutput, 1, k, 0, n);
        
        return output;
    }
    
    void combinations(vector<vector<int>>& output,
                      vector<int>& currentOutput,
                      int currentIndex,
                      int k,
                      int sum,
                      int n)
    {
        if(currentOutput.size() > k)
        {
            return;
        }
        
        if(currentOutput.size() == k)
        {
            if(sum == n)
            {
                output.push_back(currentOutput);
            }
            return;
        }
        
        for(int i = currentIndex; i < 10; i ++)
        {
            currentOutput.push_back(i);
            combinations(output, currentOutput, i + 1, k, sum + i, n);
            currentOutput.pop_back();
        }
    }
};