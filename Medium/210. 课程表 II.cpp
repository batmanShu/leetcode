class Solution {
private:
    vector<vector<int>> graph;
    vector<int> mp;
    bool isvalid;
    vector<int> result;
public:
    void dfs(int c)
    {
        if(mp[c]==2)
            return;
        mp[c]=1;
        for(auto i:graph[c])
        {
            if(mp[i]==0)
            {
                dfs(i);
                if(isvalid)
                    return;
            }
            else if(mp[i]==1)
            {
                isvalid=true;
                return;
            }
        }
        mp[c]=2;
        result.push_back(c);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        mp.resize(numCourses);
        for(auto pre:prerequisites)
        {
            graph[pre[0]].push_back(pre[1]);
        }
        for(int i=0;i<numCourses;i++)
        {
            dfs(i);
        }
        if(isvalid)
        {
            vector<int> res;
            return res;
        }
        return result;
    }
};
