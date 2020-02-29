class Solution {
public:
    int numSquares(int n) {
        vector<bool> visited(n,false);
        queue<int> q;
        int step=0;
        q.push(n);
        while(!q.empty())
        {
            step++;
            int size=q.size();
            while(size>0)
            {
                for(int i=1;q.front()-i*i>=0;i++)
                {
                    if(q.front()-i*i==0) return step;
                    if(q.front()-i*i>0)
                    {
                        if(!visited[q.front()-i*i])
                        {
                            q.push(q.front()-i*i);
                            visited[q.front()-i*i]=true;
                        }
                        
                    }
                }
                size--;
                q.pop();
            }
        } 
        return -1;
    }
};
