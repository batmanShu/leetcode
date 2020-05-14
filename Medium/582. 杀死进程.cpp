class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> res;
        if(pid.size()==0)
            return res;
        unordered_map<int,int> iskilled;
        for(int i=0;i<pid.size();i++)
        {
            iskilled[pid[i]]=0;
        }
        unordered_multimap<int, int> m;
        for (int i = 0; i < ppid.size(); i++) {
            m.insert(make_pair(ppid[i], i));
        }
        deque<int> thread2kill;
        thread2kill.push_back(kill);
        res.push_back(kill);
        iskilled[kill]=1;
        while(!thread2kill.empty())
        {
            int temp=thread2kill.front();
            thread2kill.pop_front();
            auto range = m.equal_range(temp);
            for (auto it = range.first; it != range.second; it++) {
                if(iskilled[pid[it->second]]==0)
                {
                    thread2kill.push_back(pid[it->second]);
                    res.push_back(pid[it->second]);
                    iskilled[pid[it->second]]=1;
                }
            }
        }
        return res;
    }
};
