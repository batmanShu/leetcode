class Solution {
public:
    string replaceSpace(string s) {
        int len_str=s.size();
        string ret="";
        for(int i=0;i<len_str;i++)
        {
            if(s[i]==' ')
            {
                ret=ret+"%20";
            }
            else
            {
                ret=ret+s[i];
            }
        }
        return ret;
    }
};
