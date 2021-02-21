class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==0) return;
        int l=n/2-1;
        int c=(n-1)/2;
        for(int i=0;i<=l;i++)
        {
            for(int j=0;j<=c;j++)
            {
                swap(matrix[i][j],matrix[j][n-1-i]);
                swap(matrix[i][j],matrix[n-1-i][n-1-j]);
                swap(matrix[i][j],matrix[n-1-j][i]);
            }
        }
    }
};
