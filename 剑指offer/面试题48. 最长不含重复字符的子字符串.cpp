class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int len=0;
        int maxlen=0;
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])==mp.end()||mp[s[i]]==0)
            {
                mp[s[i]]=1;
                len++;
                if(len>maxlen)
                    maxlen=len;
            }
            else
            {
                int j=i-1;
                mp.clear();
                for(;j>=0;j--)
                {
                    mp[s[j]]=1;
                    if(s[j]==s[i])
                        break;
                }
                len=i-j;
            }
        }
        return maxlen;
    }
};
