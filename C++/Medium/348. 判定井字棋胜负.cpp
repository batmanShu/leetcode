class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        p1=vector<int>(2*n+2,n);
        p2=vector<int>(2*n+2,n);
        N=n;
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
        if(player==1)
        {
            p1[row]--;
            if(p1[row]==0)
                return 1;
            p1[col+N]--;
            if(p1[col+N]==0)
                return 1;
            if(col==row)
            {
                p1[2*N]--;
                if(p1[2*N]==0)
                    return 1;
            }
            if(col+row==N-1)
            {
                p1[2*N+1]--;
                if(p1[2*N+1]==0)
                    return 1;
            }
        }
        else
        {
            p2[row]--;
            if(p2[row]==0)
                return 2;
            p2[col+N]--;
            if(p2[col+N]==0)
                return 2;
            if(col==row)
            {
                p2[2*N]--;
                if(p2[2*N]==0)
                    return 2;
            }
            if(col+row==N-1)
            {
                p2[2*N+1]--;
                if(p2[2*N+1]==0)
                    return 2;
            }
        }
        return 0;
    }
private:
    vector<int> p1;
    vector<int> p2;
    int N;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
