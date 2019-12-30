class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int maxlength=board.size()*board[0].size();
        if(word.size()>maxlength) return false;
        int* p_used=new int[maxlength]();//用于判断当前字母之前是否用过
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    if(match(board,i,j,word,0,p_used))
                    {
                        return true;
                    }
                    else memset(p_used,0,maxlength*sizeof(int));
                }
            }
        }
        return false;
    }
    bool match(vector<vector<char>>& board,int i,int j,string& word,int level,int* p){
        p[i*board[i].size()+j]=1;
        if(level==word.size()-1)
        {
            if(word[level]==board[i][j]) return true;
            else 
            {
                p[i*board[i].size()+j]=0;
                return false;
            }
        }
        if(i>0)
        {
            if(word[level+1]==board[i-1][j]&&p[(i-1)*board[i].size()+j]==0) if(match(board,i-1,j,word,level+1,p)) return true;
        }
        if(i<board.size()-1)
        {
            if(word[level+1]==board[i+1][j]&&p[(i+1)*board[i].size()+j]==0) if(match(board,i+1,j,word,level+1,p)) return true;
        }
        if(j>0)
        {
            if(word[level+1]==board[i][j-1]&&p[i*board[i].size()+j-1]==0) if(match(board,i,j-1,word,level+1,p)) return true;
        }
        if(j<board[i].size()-1)
        {
            if(word[level+1]==board[i][j+1]&&p[i*board[i].size()+j+1]==0) if(match(board,i,j+1,word,level+1,p)) return true;
        }
        p[i*board[i].size()+j]=0;
        return false;
    }
};
