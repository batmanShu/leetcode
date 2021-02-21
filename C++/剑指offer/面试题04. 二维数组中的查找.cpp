class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int row_size=matrix.size();
        if(row_size<1) return false;
        int col_size=matrix[0].size();
        int i=row_size-1;
        int j=0;
        while(i>=0&&j<col_size)
        {
            if(matrix[i][j]>target) i--;
            else if(matrix[i][j]<target) j++;
            else return true;
        }
        return false;
    }
};
