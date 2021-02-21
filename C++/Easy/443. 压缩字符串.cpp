class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==1) return chars.size();
        int cnt=1;
        int j=1;
        for(int i=1;i<chars.size();i++)
        {
            if(chars[i]==chars[i-1]) cnt++;
            else
            {
                if(cnt>1)
                {
                    string s=to_string(cnt);
                    for(int i=0;i<s.size();i++)
                    {
                        chars[j++]=s[i];
                    }
                }
                chars[j++]=chars[i];
                cnt=1;
            }
            if(i==chars.size()-1)
            {
                if(cnt>1)
                {
                    string s=to_string(cnt);
                    for(int i=0;i<s.size();i++)
                    {
                        chars[j++]=s[i];
                    }
                }
            }
        }
        return j;
    }
};
