class Solution {
public:
    int movingCount(int m, int n, int k) {
        int count=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        BFS(k,0,0,count,m,n,visited);
        return count;
    }
    bool isavaliable(int k, int i, int j)
    {
        int temp1=0;
        while(i>0)
        {
            temp1=temp1+i%10;
            i=i/10;
        }
        int temp2=0;
        while(j>0)
        {
            temp2=temp2+j%10;
            j=j/10;
        }
        if(temp1+temp2<=k) return true;
        return false;
    }
    void BFS(int k, int i, int j, int& count, int m, int n, vector<vector<bool>>& visited)
    {
        if(i<0||i>m-1||j<0||j>n-1) return;
        if(!isavaliable(k,i,j)) return;
        if(visited[i][j]) return;
        else
        {
            count++;
            visited[i][j]=true;
            BFS(k,i+1,j,count,m,n,visited);
            BFS(k,i-1,j,count,m,n,visited);
            BFS(k,i,j+1,count,m,n,visited);
            BFS(k,i,j-1,count,m,n,visited);
        }
    }
};
