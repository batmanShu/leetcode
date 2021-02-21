class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        deque<int> deque;
        while(isvisited.size()!=graph.size())
        {
            if(!deque.empty())
            {
                int cur=deque.front();
                deque.pop_front();
                isvisited[cur]=1;
                for(auto temp:graph[cur])
                {
                    if(mp.find(temp)!=mp.end())
                    {
                        if(mp[temp]==mp[cur])
                            return false;
                    }
                    else
                    {
                        mp[temp]=!mp[cur];
                    }
                    if(isvisited.find(temp)==isvisited.end())
                        deque.push_back(temp);
                }
            }
            else
            {
                for(int i=0;i<graph.size();i++)
                {
                    if(isvisited.find(i)==isvisited.end())
                    {
                        mp[i]=0;
                        for(auto temp:graph[i])
                        {
                            deque.push_back(temp);
                            mp[temp]=1;
                        }
                        isvisited[i]=1;
                        break;
                    }
                }
            }
            
        }
        return true;
    }
private:
    unordered_map<int,int> mp;
    unordered_map<int,int> isvisited;
};
