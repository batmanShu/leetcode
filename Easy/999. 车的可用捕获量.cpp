class Solution {
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int i,j;
        int res=0;
        for(i=0;i<board.size();i++)
        {
            for(j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='R')
                {
                    for(int k=0;k<4;k++)
                    {
                        int x=i,y=j;
                        while(1)
                        {
                            x+=dx[k];
                            y+=dy[k];
                            if(x<0||x>=board.size()||y<0||y>=board[0].size()) break;
                            if(board[x][y]=='p')
                            {
                                res++;
                                break;
                            }
                            else if(board[x][y]!='.')
                                break;
                        }
                    }
                    break;
                }
            }
        }
        return res;
    }
};
