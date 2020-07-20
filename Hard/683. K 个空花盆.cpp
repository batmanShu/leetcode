class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int K) {
        for(int i=0;i<bulbs.size();i++)
        {
            mp[bulbs[i]]=1;
            int j=bulbs[i]-K-1;
            if(j>0)
            {
                int flag=1;
                if(mp.find(j)!=mp.end())
                {
                    for(int t=j+1;t<bulbs[i];t++)
                    {
                        if(mp.find(t)!=mp.end())
                        {
                            flag=0; 
                            break;
                        }
                    }
                    if(flag)
                        return i+1;
                }
            }
            j=bulbs[i]+K+1;
            if(j<bulbs.size()+1)
            {
                int flag=1;
                if(mp.find(j)!=mp.end())
                {
                    for(int t=bulbs[i]+1;t<j;t++)
                    {
                        if(mp.find(t)!=mp.end())
                        {
                            flag=0; 
                            break;
                        }
                    }
                    if(flag)
                        return i+1;
                }
            }
        }
        return -1;
    }
private:
    unordered_map<int,int> mp;
};
