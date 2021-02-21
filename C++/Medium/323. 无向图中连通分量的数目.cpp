class Solution {
private:
    vector<int> parents;

    int find(int x){
        return parents[x]==x?x:(parents[x]=find(parents[x]));
    }

    void to_union(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px!=py)
        {
            parents[y]=px;
            for(int i=0;i<parents.size();i++)
                if(parents[i]==py)
                    parents[i]=px;
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        set<int> s;
        for(int i=0;i<n;i++)
        {
            parents.push_back(i);
        }
        for(int i=0;i<edges.size();i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            to_union(a,b);
        }
        for(int i=0;i<n;i++)
        {
            s.insert(parents[i]);
        }
        return s.size();
    }
};
