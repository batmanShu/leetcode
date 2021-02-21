class Solution {
public:
    string alienOrder(vector<string>& words) {
        for(int i=0;i<words.size()-1;i++)
        {
            int j;
            for(j=0;j<words[i].size()&&j<words[i+1].size();j++)
            {
                if(words[i][j]==words[i+1][j])
                {
                    continue;
                }
                else
                {
                    if(mp.count(words[i][j])!=0)
                    {
                        mp[words[i][j]].insert(words[i+1][j]);
                    }
                    else
                    {
                        set<char> s;
                        s.insert(words[i+1][j]);
                        mp[words[i][j]]=s;
                    }
                }
                break;
            }
            if(j==words[i+1].size()&&j<words[i].size())
                return "";
        }
        indegrees=vector<int>(26,-1);
        for(int i=0;i<words.size();i++)
        {
            for(auto c:words[i])
            {
                int ind=c-'a';
                indegrees[ind]=0;
            }
        }
        for(auto itr=mp.begin();itr!=mp.end();itr++)
        {
            for(auto c:itr->second)
            {
                int ind=c-'a';
                indegrees[ind]++;
            }
        }
        list<char> l;
        int count=0;
        for(int i=0;i<26;i++)
        {
            if(indegrees[i]!=-1)
                count++;
            char c='a'+i;
            if(indegrees[i]==0)
                l.push_back(c);
        }
        string result="";
        while(!l.empty())
        {
            char c=l.front();
            l.pop_front();
            indegrees[c-'a']=-1;
            result+=c;
            for(auto n:mp[c])
            {
                indegrees[n-'a']--;
                if(indegrees[n-'a']==0)
                    l.push_back(n);
            }
        }
        if(result.size()!=count)
            return "";
        return result;
    }
private:
    unordered_map<char,set<char>> mp; 
    vector<int> indegrees;
};
