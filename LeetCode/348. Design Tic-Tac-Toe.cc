class TicTacToe {
public:
    int *rows[2];
    int *cols[2];
    int *diags[2];
    int size;
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        for(int i = 0; i < 2; i ++)
        {
            rows[i] = new int[n];
            cols[i] = new int[n];
            diags[i] = new int[2];
            
            for(int j = 0; j < 2; j ++)
            {
                diags[i][j] = 0;
            }
            
            for(int j = 0; j < n; j ++)
            {
                rows[i][j] = 0;
                cols[i][j] = 0;
            }
        }
        
        size = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int playerId = player - 1;
        
        rows[playerId][row] ++;
        cols[playerId][col] ++;
        
        if(row == col)
        {
            diags[playerId][0] ++;
            
            if(row == size / 2)
            {
                diags[playerId][1] ++;
            }
        }
        else if(row == size - col - 1 || col == size - row - 1)
        {
            diags[playerId][1] ++;
        }
        
        if(rows[playerId][row] == size || cols[playerId][col] == size || diags[playerId][0] == size || diags[playerId][1] == size)
        {
            return player;
        }
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */