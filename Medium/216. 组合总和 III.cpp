class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        for(int i=1;i<=9;i++)
            dfs(i,k,n,temp);
        return ans;
    }

    void dfs(int i,int k,int n,vector<int>& temp) {
        if(k<0)
            return;
        int nextn=n-i;
        if(nextn>0)
        {
            temp.push_back(i);
            for(int j=i+1;j<=9;j++)
            {
                dfs(j,k-1,nextn,temp);
            }
            temp.pop_back();
        }
        else if(nextn==0&&k==1)
        {
            temp.push_back(i);
            ans.push_back(temp);
            temp.pop_back();
        }
    }
private:
    vector<vector<int>> ans;
};
