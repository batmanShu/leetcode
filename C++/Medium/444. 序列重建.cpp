class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n=org.size();
        indegree=vector<int>(n+1,-1);
        for(auto seq:seqs)
        {
            if(seq.size()>n)
                return false;
            for(int i=0;i<seq.size();i++)
            {
                if(seq[i]>n)
                    return false;
                indegree[seq[i]]=0;
            }
        }
        for(auto seq:seqs)
        {
            for(int i=0;i<seq.size()-1;i++)
            {
                mp[seq[i]].push_back(seq[i+1]);
                indegree[seq[i+1]]++;
            }
        }
        int flag=0;
        vector<int> ans;
        for(int i=1;i<=n;i++)
        {
            if(indegree[i]==-1)
                return false;
            if(indegree[i]==0)
            {
                if(flag)
                    return false;
                flag=1;
                ans.push_back(i);
            }
        }
        if(ans.size()==0)
            return false;
        flag=0;
        while(ans.size()!=n)
        {
            int cur=ans.back();
            if(indegree[cur]==-1)
                return false;
            indegree[cur]=-1;
            for(int i=0;i<mp[cur].size();i++)
            {
                indegree[mp[cur][i]]--;
                if(indegree[mp[cur][i]]==0)
                {
                    if(flag)
                        return false;
                    flag=1;
                    ans.push_back(mp[cur][i]);
                }
            }
            flag=0;
        }
        if(ans==org)
            return true;
        return false;
    }
private:
    vector<int> indegree;
    unordered_map<int,vector<int>> mp;
};
