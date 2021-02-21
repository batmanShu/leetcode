class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        ans=0;
        dfs(0,rooms);
        if(ans==rooms.size())
            return true;
        return false;
    }
private:
    unordered_map<int, int> isvisited;
    int ans;
    void dfs(int i,vector<vector<int>>& rooms){
        if(isvisited.find(i)==isvisited.end())
        {
            isvisited[i]=1;
            ans++;
            for(int j=0;j<rooms[i].size();j++)
            {
                dfs(rooms[i][j],rooms);
            }
        }
    }
};
