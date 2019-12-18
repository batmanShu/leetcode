class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size();
        if(m==0) return res;
        int n=matrix[0].size();
        if(n==0) return res;
        int i=0,j=0;
        while(m>0&&n>0)
        {
            int i0=i;
            int j0=i;
            if(i>=j0+n) break;
            for(j=i;j<j0+n;j++)
            {
                res.push_back(matrix[i][j]);
            }
            j--;
            if(i+1>=i0+m) break;
            for(i=i+1;i<i0+m;i++)
            {
                res.push_back(matrix[i][j]);
            }
            i--;
            if(j-1<=j0-1) break;
            for(j=j-1;j>j0-1;j--)
            {
                res.push_back(matrix[i][j]);
            }
            j++;
            if(i-1<=i0) break;
            for(i=i-1;i>i0;i--)
            {
                res.push_back(matrix[i][j]);
            }
            i++;
            m=m-2;
            n=n-2;
        }
        return res;
    }
};
