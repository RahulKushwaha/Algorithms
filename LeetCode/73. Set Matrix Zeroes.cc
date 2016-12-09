class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows;
        unordered_set<int> columns;
        
        for(int i = 0; i < matrix.size(); i ++)
        {
            for( int j = 0; j < matrix[i].size(); j ++)
            {
                if(matrix[i][j] == 0)
                {
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        
        
        for(unordered_set<int>::iterator rowItr = rows.begin(); rowItr != rows.end(); rowItr ++)
        {
            for(int j = 0; j < matrix[*rowItr].size(); j ++)
            {
                matrix[*rowItr][j] = 0;
            }
        }
        
        for(unordered_set<int>::iterator colItr = columns.begin(); colItr != columns.end(); colItr ++)
        {
            for(int i = 0; i < matrix.size(); i ++)
            {
                matrix[i][*colItr] = 0;
            }
        }
    }
};