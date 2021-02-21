class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        for(int i=0;i<rooms.size();i++)
        {
            for(int j=0;j<rooms[0].size();j++)
            {
                if(rooms[i][j]==0)
                    bfs(i,j,rooms,0);
            }
        }
    }
    void bfs(int i,int j,vector<vector<int>>& rooms,int curd) {
        if(i<0||i>rooms.size()-1||j<0||j>rooms[0].size()-1)
            return;
        if(rooms[i][j]==-1)
            return;
        else
        {
            if(rooms[i][j]<curd)
                return;
            rooms[i][j]=curd;
            bfs(i+1,j,rooms,curd+1);
            bfs(i-1,j,rooms,curd+1);
            bfs(i,j+1,rooms,curd+1);
            bfs(i,j-1,rooms,curd+1);
        }
    }
};
