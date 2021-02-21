class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N=matrix.size();
        int temp=0;
        int n=0;
        for(int i=0;i<N/2;i++)
        {
            n=N-2*i;
            for(int j=i;j<n+i-1;j++)
            {
                temp=matrix[2*i-j+n-1][i];
                matrix[2*i-j+n-1][i]=matrix[i+n-1][2*i-j+n-1];
                matrix[i+n-1][2*i-j+n-1]=matrix[j][i+n-1];
                matrix[j][i+n-1]=matrix[i][j];
                matrix[i][j]=temp;
            }
        }
    }
};
