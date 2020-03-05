class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> mp;
        for(int i=0;i<equations.size();i++)
        {
            mp[equations[i][0]].push_back(make_pair(equations[i][1],values[i]));
            mp[equations[i][1]].push_back(make_pair(equations[i][0],1/values[i]));
        }
        vector<double> ret;
        for(auto q:queries)
        {
            double temp=BFS(q[0],q[1],mp);
            ret.push_back(temp);
        }
        return ret;
    }
    double BFS(string s1, string s2, unordered_map<string,vector<pair<string,double>>> mp)
    {
        if(mp.find(s1)==mp.end()||mp.find(s2)==mp.end()) return -1.0;
        if(s1==s2) return 1.0;
        queue<pair<string,double>> q;
        q.push(make_pair(s1,1.0));
        unordered_map<string,bool> visited(false);
        while(!q.empty())
        {
            pair<string,double> front=q.front();
            q.pop();
            if(!visited[front.first])
            {
                for(auto f:mp[front.first])
                {
                    if(f.first==s2) return f.second*front.second;
                    q.push(make_pair(f.first,f.second*front.second));
                }
            }
            visited[front.first]=true;
        }
        return -1.0;
    }
};
