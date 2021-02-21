class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<int> mp(10,0);
        int res=0;
        for(int i=m;i<=n;i++)
        {
            for(int j=1;j<=9;j++)
            {
                mp[j]=1;
                res+=dfs(j,i-1,mp);
                mp[j]=0;
            }
        }
        return res;
    }
    int dfs(int num,int n,vector<int>& visited) {
        if(n==0) return 1;
        int res=0;
        for(int i=1;i<=9;i++)
        {
            if(num==i) continue;
            if(connectable(num,i,visited))
            {
                visited[i]=1;
                res+=dfs(i,n-1,visited);
                visited[i]=0;
            }
        }
        return res;
    }
    bool connectable(int i, int j, vector<int>& mp) {
        if(mp[j]==1) return false;
        if(i==1)
        {
            if(j==3)
            {
                if(mp[2]!=1)
                    return false;
            }
            else if(j==7)
            {
                if(mp[4]!=1)
                    return false;
            }
            else if(j==9)
            {
                if(mp[5]!=1)
                    return false;
            }
        }
        else if(i==3)
        {
            if(j==1)
            {
                if(mp[2]!=1)
                    return false;
            }
            else if(j==7)
            {
                if(mp[5]!=1)
                    return false;
            }
            else if(j==9)
            {
                if(mp[6]!=1)
                    return false;
            }
        }
        else if(i==7)
        {
            if(j==1)
            {
                if(mp[4]!=1)
                    return false;
            }
            else if(j==3)
            {
                if(mp[5]!=1)
                    return false;
            }
            else if(j==9)
            {
                if(mp[8]!=1)
                    return false;
            }
        }
        else if(i==9)
        {
            if(j==1)
            {
                if(mp[5]!=1)
                    return false;
            }
            else if(j==7)
            {
                if(mp[8]!=1)
                    return false;
            }
            else if(j==3)
            {
                if(mp[6]!=1)
                    return false;
            }
        }
        else if(i==2)
        {
            if(j==8)
            {
                if(mp[5]!=1)
                    return false;
            }
        }
        else if(i==4)
        {
            if(j==6)
            {
                if(mp[5]!=1)
                    return false;
            }
        }
        else if(i==6)
        {
            if(j==4)
            {
                if(mp[5]!=1)
                    return false;
            }
        }
        else if(i==8)
        {
            if(j==2)
            {
                if(mp[5]!=1)
                    return false;
            }
        }
        return true;
    }
};
