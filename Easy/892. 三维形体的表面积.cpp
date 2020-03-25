class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        res=0;
        int N=grid.size();
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                int layer=grid[i][j];
                if(layer>0) res+=2+layer*4;
                sidearea(i,j,layer,grid);
            }
        }
        return res;
    }
    void sidearea(int i, int j, int l, vector<vector<int>> grid) {
        sideareacore(i+1,j,l,grid);
        //sideareacore(i-1,j,l,grid);
        sideareacore(i,j+1,l,grid);
        //sideareacore(i,j-1,l,grid);
    }
    void sideareacore(int i, int j, int l, vector<vector<int>> grid) {
        if(i<0||i>=grid.size()||j<0||j>=grid.size())
        {
            return;
        }
        res-=2*min(l,grid[i][j]);
    }
private:
    int res;
};
