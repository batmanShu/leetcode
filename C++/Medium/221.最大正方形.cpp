class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int sidelength=0;
        int maxsidelength=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]=='1')
                {
                    sidelength=1;
                    int m=i,n=j;
                    while(n+1<matrix[m].size()&&matrix[m][++n]=='1'&&m+1<matrix.size()&&matrix[++m][n]=='1')
                    {
                        int flag=1;
                        for(int k=i;k<=m;k++)
                        {
                            for(int l=j;l<=n;l++)
                            {
                                if(matrix[k][l]!='1') flag=0;
                            }
                        }
                        if(flag==1) sidelength++;
                    }
                    if(maxsidelength<sidelength) maxsidelength=sidelength;
                }
            }
        }
        return maxsidelength*maxsidelength;
    }
};
