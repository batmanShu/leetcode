class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        for(int i=1;i<=n;i++)
        {
            vector<int> temp;
            dfs(i,n,k,temp);
        }
        return ans;
    }
private:
    vector<vector<int>> ans;
    void dfs(int i, int n, int k, vector<int>& temp) {
        if(k>0)
        {
            temp.push_back(i);
            k--;
            if(k==0)
            {
                ans.push_back(temp);
                return;
            }
            for(int j=i+1;j<=n;j++)
            {
                dfs(j,n,k,temp);
                temp.pop_back();
            }
        }
    }
};
