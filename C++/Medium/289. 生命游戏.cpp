class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> next_board=board;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                next_board[i][j]=update(i,j,board);
            }
        }
        board=next_board;
    }
    int update(int i, int j, vector<vector<int>> board) {
        int sum=0;
        sum=getboard(i-1,j-1,board)+getboard(i-1,j,board)+getboard(i-1,j+1,board)+getboard(i,j-1,board)+getboard(i,j+1,board)+getboard(i+1,j-1,board)+getboard(i+1,j,board)+getboard(i+1,j+1,board);
        if(board[i][j]==1)
        {
            if(sum<2) return 0;
            else if(sum>3) return 0;
            else return 1;
        }
        else
        {
            if(sum==3) return 1;
            else return 0;
        }
    }
    int getboard(int i, int j, vector<vector<int>> board) {
        if(i<0||i>board.size()-1||j<0||j>board[0].size()-1) return 0;
        return board[i][j];
    }
};
