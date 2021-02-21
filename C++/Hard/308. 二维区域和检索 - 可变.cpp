class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        mat=matrix;
        sum=mat;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(i>0)
                {
                    if(j>0)
                        sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
                    else
                        sum[i][j]+=sum[i-1][j];
                }
                else
                {
                    if(j>0)
                        sum[i][j]+=sum[i][j-1];
                }
            }
        }
    }
    
    void update(int row, int col, int val) {
        int diff=val-mat[row][col];
        mat[row][col]=val;
        for(int i=row;i<mat.size();i++)
        {
            for(int j=col;j<mat[0].size();j++)
            {
                sum[i][j]+=diff;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res=sum[row2][col2];
        if(row1>0)
        {
            if(col1>0)
            {
                res=res+sum[row1-1][col1-1]-sum[row2][col1-1]-sum[row1-1][col2];
            }
            else
            {
                res=res-sum[row1-1][col2];
            }
        }
        else
        {
            if(col1>0)
                res=res-sum[row2][col1-1];
        }
        return res;
    }
private:
    vector<vector<int>> mat;
    vector<vector<int>> sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
