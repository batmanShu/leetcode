class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int flag=1;
        while(flag)
        {
            flag=0;
            for(int i=0;i<matrix.size();i++)
            {
                for(int j=0;j<matrix[0].size();j++)
                {
                    if(update(i,j,matrix)) 
                    {
                        flag=1;
                    }
                }
            }
        }
        return matrix;
    }
    bool update(int i, int j, vector<vector<int>>& matrix) {
        if(i<0||i>matrix.size()-1||j<0||j>matrix[0].size()-1)
            return false;
            int temp=matrix[i][j];
        if(matrix[i][j]!=0)
        {
            matrix[i][j]=min(getvalue(i+1,j,matrix),min(getvalue(i-1,j,matrix),min(getvalue(i,j-1,matrix),getvalue(i,j+1,matrix))))+1;
        }
        if(matrix[i][j]!=temp) return true;
        return false;
    }
    int getvalue(int i, int j, vector<vector<int>>& matrix) {
        if(i<0||i>matrix.size()-1||j<0||j>matrix[0].size()-1)
        {
            return INT_MAX;
        }
        return matrix[i][j];
    }
};
