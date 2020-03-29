class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        distance=vector<vector<int>>(grid.size(),vector<int>(grid[0].size(),300));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1) distance[i][j]=0;
                else
                {
                    if(i>0&&j>0) distance[i][j]=min(distance[i-1][j],distance[i][j-1])+1;
                    else if(i>0) distance[i][j]=distance[i-1][j]+1;
                    else if(j>0) distance[i][j]=distance[i][j-1]+1;
                }
            }
        }
        for(int i=grid.size()-1;i>=0;i--)
        {
            for(int j=grid[0].size()-1;j>=0;j--)
            {
                if(grid[i][j]==1) distance[i][j]=0;
                else
                {
                    int temp=distance[i][j];
                    if(i<grid.size()-1&&j<grid[0].size()-1) temp=min(distance[i+1][j],distance[i][j+1])+1;
                    else if(i<grid.size()-1) temp=distance[i+1][j]+1;
                    else if(j<grid[0].size()-1) temp=distance[i][j+1]+1;
                    if(temp<distance[i][j]) distance[i][j]=temp;
                }
            }
        }
        int res=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(distance[i][j]>res) res=distance[i][j];
            }
        }
        if(res>=300||res==0) res=-1;
        return res;
    }
private:
    vector<vector<int>> distance;
};
