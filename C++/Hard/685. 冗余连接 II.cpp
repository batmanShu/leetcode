class Solution {
private:
    vector<int> parents;
    vector<int> indegree;

    int find(int x){
        return parents[x]==x?x:find(parents[x]);
    }

    bool to_union(int x,int y){
        int p1=find(x);
        int p2=find(y);
        if(p1==p2)
            return false;
        parents[y]=parents[x];
        return true;
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parents.push_back(0);
        indegree.push_back(0);
        for(int i=1;i<n+1;i++)
        {
            parents.push_back(i);
            indegree.push_back(0);
        }
        int flag=0;
        int a,b;
        for(int i=0;i<n;i++)
        {
            indegree[edges[i][1]]++;
            if(indegree[edges[i][1]]==2)
            {
                a=edges[i][0];
                b=edges[i][1];
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            for(int i=0;i<n;i++)
                if(!to_union(edges[i][0],edges[i][1]))
                    return {edges[i][0],edges[i][1]};
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(edges[i][0]==a&&edges[i][1]==b)
                    continue;
                else
                {
                    if(!to_union(edges[i][0],edges[i][1]))
                    {
                        for(auto e:edges)
                        {
                            if(e[0]!=a&&e[1]==b)
                                return {e[0],e[1]};
                        }
                    }
                }
            }
        }
        return {a,b};
    }
};
