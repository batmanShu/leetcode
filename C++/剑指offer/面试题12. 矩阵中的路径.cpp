class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->board=board;
        this->word=word;
        int m=board.size();
        if(m<1) return false;
        int n=board[0].size();
        int index=-1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(find(i,j,index)) return true;
            }
        }
        return false;
    }
    bool find(int i, int j, int index)
    {
        if(i<0||i>board.size()-1||j<0||j>board[0].size()-1) return false;
        index++;
        if(board[i][j]!=word[index])
        {
            return false;
        }
        if(board[i][j]==word[index]&&index==word.size()-1) return true;
        char temp=board[i][j];
        board[i][j]=' ';
        bool res=find(i-1,j,index)||find(i+1,j,index)||find(i,j-1,index)||find(i,j+1,index);
        board[i][j]=temp;
        return res;
    }
private:
    vector<vector<char>> board;
    string word;
};
