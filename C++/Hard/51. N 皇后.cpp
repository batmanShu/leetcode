class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> queens(n,-1);
        set<int> diagonals1;
        set<int> diagonals2;
        set<int> rows;
        set<int> cols;
        for(int i=0;i<queens.size();i++)
            backtrack(0,i,queens,diagonals1,diagonals2,cols);
        return ans;
    }

    void backtrack(int i,int j,vector<int>& queens,set<int>& diagonals1,set<int>& diagonals2,set<int>& cols) {
        if(diagonals1.count(i-j)||diagonals2.count(i+j)||cols.count(j))
            return;
        queens[i]=j;
        if(i==queens.size()-1)
        {
            vector<string> temp=generateanswer(queens);
            ans.push_back(temp);
            return;
        }
        diagonals1.insert(i-j);
        diagonals2.insert(i+j);
        cols.insert(j);
        for(int k=0;k<queens.size();k++)
        {
            backtrack(i+1,k,queens,diagonals1,diagonals2,cols);
        }
        diagonals1.erase(i-j);
        diagonals2.erase(i+j);
        cols.erase(j);
    }
private:
    vector<vector<string>> ans;
    vector<string> generateanswer(vector<int> queens){
        vector<string> a;
        for(int i=0;i<queens.size();i++)
        {
            string temp="";
            for(int j=0;j<queens.size();j++)
            {
                if(queens[i]==j)
                    temp+='Q';
                else
                    temp+='.';
            }
            a.push_back(temp);
        }
        return a;
    }
};
