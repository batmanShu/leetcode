class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> minfreq(26,INT_MAX);
        for(auto s:A)
        {
            vector<int> freq(26,0);
            for(int i=0;i<s.size();i++)
            {
                freq[s[i]-'a']++;
            }
            for(int i=0;i<26;i++)
                minfreq[i]=min(minfreq[i],freq[i]);
        }
        vector<string> ans;
        for(int i=0;i<26;i++)
        {
            if(minfreq[i]!=INT_MAX)
            {
                char c='a'+i;
                string s;
                s.push_back(c);
                for(int j=0;j<minfreq[i];j++)
                    ans.push_back(s);
            }
        }
        return ans;
    }
};
