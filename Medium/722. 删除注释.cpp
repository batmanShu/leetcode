class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        int p_comment=0;
        int line_end=1;
        string cur_line="";
        for(int i=0;i<source.size();i++)
        {
            string s=source[i];
            for(int j=0;j<s.size();j++)
            {
                if(p_comment==0&&s[j]=='/')
                {
                    if(j+1<s.size()&&s[j+1]=='/')
                    {
                        break;
                    }
                    else if(j+1<s.size()&&s[j+1]=='*')
                    {
                        p_comment=1;
                        line_end=0;
                        j++;
                    }
                    else
                        cur_line+=s[j];
                }
                else if(p_comment==1&&s[j]=='*')
                {
                    if(j+1<s.size()&&s[j+1]=='/')
                    {
                        p_comment=0;
                        line_end=1;
                        j++;
                    }
                }
                else if(p_comment==0)
                    cur_line+=s[j];
            }
            if(line_end==1&&cur_line.size()>0)
            {
                ans.push_back(cur_line);
                cur_line="";
            }
        }
        return ans;
    }
};
