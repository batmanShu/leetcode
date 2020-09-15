class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> row(9,0);
        vector<int> col(9,0);
        vector<int> square(9,0);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    int num=board[i][j]-'0';
                    num=1<<(num-1);
                    row[i]=row[i]|num;
                    col[j]=col[j]|num;
                    square[i/3*3+j/3]=square[i/3*3+j/3]|num;
                }
            }
        }
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(int num=1;num<=9;num++)
                    {
                        if(dfs(num,i,j,row,col,square,board))
                            return;
                    }
                }
            }
        }
    }

    bool dfs(int num,int i,int j,vector<int>& row,vector<int>& col,vector<int>& square,vector<vector<char>>& board) {
        if(!isvalid(num,i,j,row,col,square,board))
            return false;
        board[i][j]='0'+num;
        num=1<<(num-1);
        row[i]=row[i]|num;
        col[j]=col[j]|num;
        square[i/3*3+j/3]=square[i/3*3+j/3]|num;
        int flag=0;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    flag=1;
                    for(int n=1;n<=9;n++)
                    {
                        if(dfs(n,i,j,row,col,square,board))
                            return true;
                    }
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag==0)
            return true;
        board[i][j]='.';
        row[i]=row[i]^num;
        col[j]=col[j]^num;
        square[i/3*3+j/3]=square[i/3*3+j/3]^num;
        return false;
    }

    bool isvalid(int num,int i,int j,vector<int>& row,vector<int>& col,vector<int>& square,vector<vector<char>>& board) {
        if(i<0||i>=board.size()||j<0||j>=board[0].size())
            return false;
        if(board[i][j]!='.')
            return false;
        num=1<<(num-1);
        if(((num&row[i])==0)&&((num&col[j])==0)&&((num&square[i/3*3+j/3])==0))
            return true;
        return false;
    }
};
