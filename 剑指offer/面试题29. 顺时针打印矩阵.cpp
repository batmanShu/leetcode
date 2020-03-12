class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()==0||matrix[0].size()==0) return res;
        vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        int h=matrix.size();
        int w=matrix[0].size();
        int x=0,y=0,curdir=0;
        while(res.size()<w*h)
        {
            if(x>=0&&x<h&&y>=0&&y<w&&matrix[x][y]!=INT_MAX)
            {
                res.push_back(matrix[x][y]);
                matrix[x][y]=INT_MAX;
            } 
            x+=dir[curdir][0];
            y+=dir[curdir][1];
            if(x<0||x>=h||y<0||y>=w||matrix[x][y]==INT_MAX)
            {
                x-=dir[curdir][0];
                y-=dir[curdir][1];
                curdir=(curdir+1)%4;
            }
        }
        return res;
    }
};
