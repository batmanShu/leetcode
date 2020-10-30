class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    ans+=core(i+1,j,grid);
                    ans+=core(i-1,j,grid);
                    ans+=core(i,j+1,grid);
                    ans+=core(i,j-1,grid);
                }
            }
        }
        return ans;
    }
private:
    int core(int i,int j,vector<vector<int>>& grid){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size())
            return 1;
        if(grid[i][j]==0)
            return 1;
        else
            return 0;
    }
};
