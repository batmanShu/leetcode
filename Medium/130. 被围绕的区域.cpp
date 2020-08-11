class Solution {
public:
    void solve(vector<vector<char>>& board) {
        h=board.size();
        if(h==0)
            return;
        w=board[0].size();
        for(int i=0;i<w;i++)
        {
            dfs(0,i,board);
            dfs(h-1,i,board);
        }
        for(int i=0;i<h;i++)
        {
            dfs(i,0,board);
            dfs(i,w-1,board);
        }
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='F')
                    board[i][j]='O';
            }
        }    
    }

    void dfs(int i,int j,vector<vector<char>>& board) {
        if(i<0||i>=h||j<0||j>=w)
            return;
        if(board[i][j]=='O')
        {
            board[i][j]='F';
            dfs(i+1,j,board);
            dfs(i-1,j,board);
            dfs(i,j+1,board);
            dfs(i,j-1,board);
        }
    }
private:
    int h,w;
};
