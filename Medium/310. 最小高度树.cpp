class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        if(n==2)
            return {0,1};
        vector<int> indgree(n,0);
        vector<vector<int>> graph(n,vector<int>());
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            indgree[edges[i][0]]++;
            indgree[edges[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<indgree.size();i++)
        {
            if(indgree[i]==1)
                q.push(i);
        }
        int cnt;
        while(n>2)
        {
            cnt=q.size();
            n-=cnt;
            while(cnt--)
            {
                int temp=q.front();
                q.pop();
                for(int i=0;i<graph[temp].size();i++)
                {
                    if(indgree[graph[temp][i]]!=0)
                    {
                        indgree[graph[temp][i]]--;
                        if(indgree[graph[temp][i]]==1)
                            q.push(graph[temp][i]);
                    }
                }
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }

};
