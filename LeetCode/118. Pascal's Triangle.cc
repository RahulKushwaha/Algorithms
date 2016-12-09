class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output;
        if(numRows == 0)
        {
            return output;
        }
        
        vector<int> current;
        current.push_back(1);
        output.push_back(current);
        
        for(int i = 1; i < numRows; i ++)
        {
            current.clear();
            current.push_back(1);
            int j;
            for(j = 1; j < output[i - 1].size(); j ++)
            {
                current.push_back(output[i - 1][j - 1] + output[i - 1][j]);
            }
            
            current.push_back(1);

            output.push_back(current);
        }
        
        return output;
    }
};