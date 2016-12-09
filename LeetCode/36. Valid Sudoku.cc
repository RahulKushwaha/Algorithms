class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Any array which is initialized, but has part that is beyond the initialization, is initialized to 0
        /*
        int const A::test[10][10];           // uninitialized
        int const A::test[10][10] = { {0} }; // all elements initialized to 0.
        int const A::test[10][10] = {1,2};   // test[0][0] ==1, test[0][1]==2, rest==0
        */

        bool rows[9][9] = {0};
        bool cols[9][9] = {0};
        bool units[9][9] = {0};

        for(int i = 0; i < 9; i ++)
        {
            for(int j = 0; j < 9; j ++)
            {
                int unitIndex = (i / 3) * 3 + (j / 3);
                int val = board[i][j] - '1';
                
                if(board[i][j] != '.')
                {
                    if(rows[i][val] || cols[j][val] || units[unitIndex][val])
                    {
                        return false;
                    }
                    
                    rows[i][val] = true;
                    cols[j][val] = true;
                    units[unitIndex][val] = true;
                }
            }
        }
        
        return true;
    }
};