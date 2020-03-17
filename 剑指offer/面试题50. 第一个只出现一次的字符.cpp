class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> c(26,0);
        for(int i=0;i<s.size();i++)
        {
            c[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++)
        {
            if(c[s[i]-'a']==1)
                return s[i];
        }
        return ' ';
    }
};
