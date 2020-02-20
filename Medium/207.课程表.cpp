class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjac(numCourses,vector<int>());
        vector<int> node;
        int indegree[numCourses];
        memset(indegree,0,sizeof(indegree));
        for(auto pre:prerequisites)
        {
            adjac[pre[0]].push_back(pre[1]);
            indegree[pre[1]]++;
        }
        queue<int> qu;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                qu.push(i);
                node.push_back(i);
            }   
        }
        while(!qu.empty())
        {
            int j=qu.front();
            qu.pop();
            for(auto itr:adjac[j])
            {
                indegree[itr]--;
                if(indegree[itr]==0)
                {
                    qu.push(itr);
                    node.push_back(itr);
                }
            }        
        }
        return node.size()==numCourses;
    }
};
