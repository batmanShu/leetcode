class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int i=click[0];
        int j=click[1];
        if(board[i][j]=='M')
        {
            board[i][j]='X';
            return board;
        }
        else
        {
            clickcore(board,i,j);
        }
        return board;
    }

private:
    void clickcore(vector<vector<char>>& board, int i, int j) {
        if(i<0||i>=board.size()||j<0||j>=board[0].size())
            return;
        if(board[i][j]=='E')
        {
            int n=checkneighbor(board,i,j);
            if(n>0)
            {
                char c='0'+n;
                board[i][j]=c;
                return;
            }
            board[i][j]='B';
            clickcore(board,i+1,j);
            clickcore(board,i-1,j);
            clickcore(board,i,j+1);
            clickcore(board,i,j-1);
            clickcore(board,i+1,j+1);
            clickcore(board,i-1,j+1);
            clickcore(board,i+1,j-1);
            clickcore(board,i-1,j-1);
        }
    }
    int checkneighbor(vector<vector<char>>& board, int i, int j) {
        int ans=0;
        if(check(board,i+1,j))
            ans++;
        if(check(board,i,j+1))
            ans++;
        if(check(board,i-1,j))
            ans++;
        if(check(board,i,j-1))
            ans++;
        if(check(board,i-1,j-1))
            ans++;
        if(check(board,i+1,j-1))
            ans++;
        if(check(board,i+1,j+1))
            ans++;
        if(check(board,i-1,j+1))
            ans++;
        return ans;
    }

    bool check(vector<vector<char>>& board, int i, int j) {
        if(i<0||i>=board.size()||j<0||j>=board[0].size())
            return false;
        if(board[i][j]=='M')
            return true;
        return false;
    }
};
