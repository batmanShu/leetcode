class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return 0;
        int ans=0;
        dp=vector<vector<int>>(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                int temp;
                temp=core(matrix,i,j);
                ans=max(ans,temp);
            }
        }
        return ans;
    }
    int core(vector<vector<int>>& matrix,int i,int j) {
        if(i<0||i>=matrix.size()||j<0||j>=matrix[0].size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=0;
        int val=matrix[i][j];
        if(check(matrix,i+1,j,val))
            ans=max(ans,core(matrix,i+1,j));
        if(check(matrix,i-1,j,val))
            ans=max(ans,core(matrix,i-1,j));
        if(check(matrix,i,j+1,val))
            ans=max(ans,core(matrix,i,j+1));
        if(check(matrix,i,j-1,val))
            ans=max(ans,core(matrix,i,j-1));
        dp[i][j]=1+ans;
        return dp[i][j];
    }
    bool check(vector<vector<int>>& matrix,int i,int j,int val) {
        if(i<0||i>=matrix.size()||j<0||j>=matrix[0].size())
            return false;
        if(matrix[i][j]<=val)
            return false;
        return true;
    }
private:
    vector<vector<int>> dp;
};
