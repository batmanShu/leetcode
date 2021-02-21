class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int res=0;
        int num_tasks=0;
        unordered_map<char,int> mp;
        priority_queue<int> q;
        for(auto task:tasks)
        {
            if(mp.count(task)==0)
            {
                mp[task]=1;
                num_tasks++;
            } 
            else
                mp[task]++;
        }
        for(auto task:mp)
        {
            q.push(task.second);
        }
        int maxnum=q.top();
        int count=1;
        q.pop();
        while(!q.empty()&&q.top()==maxnum) 
        {
            n--;
            count++;
            q.pop();
        }
        if(n<=0) return tasks.size();
        int space=(maxnum-1)*n;
        if(tasks.size()-maxnum*count<space)
        {
            res=maxnum*(n+count)-n;
        }
        else
        {
            res=tasks.size();
        }
        return res;
    }
};
