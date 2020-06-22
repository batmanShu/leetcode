class Solution {
public:
    bool patternMatching(string pattern, string value) {
        int cnt_a=0;
        int cnt_b=0;
        for(auto ch:pattern)
        {
            if(ch=='a')
                cnt_a++;
            else
                cnt_b++;
        }
        if(cnt_a<cnt_b)
        {
            swap(cnt_a,cnt_b);
            for(auto& ch:pattern)
            {
                ch=(ch=='a')?'b':'a';
            }
        }
        if(value.size()==0)
            return cnt_b==0;
        if(pattern.size()==0)
            return false;
        int len_a,len_b;
        bool correct;
        for(len_a=0;cnt_a*len_a<=value.size();len_a++)
        {
            string str_a,str_b;
            correct=true;
            int sum_len_b=value.size()-cnt_a*len_a;
            if((sum_len_b==0&&cnt_b==0)||(cnt_b!=0&&sum_len_b%cnt_b==0))
            {
                len_b=(cnt_b==0)?0:(sum_len_b/cnt_b);
                int pos=0;
                for(auto ch:pattern)
                {
                    if(ch=='a')
                    {
                        if(str_a.size()==0)
                        {
                            str_a=value.substr(pos,len_a);
                        }
                        else
                        {
                            string temp=value.substr(pos,len_a);
                            if(temp!=str_a)
                            {
                                correct=false;
                                break;
                            }
                        }
                        pos+=len_a;
                    }
                    else
                    {
                        if(str_b.size()==0)
                        {
                            str_b=value.substr(pos,len_b);
                        }
                        else
                        {
                            string temp=value.substr(pos,len_b);
                            if(temp!=str_b)
                            {
                                correct=false;
                                break;
                            }
                        }
                        pos+=len_b;
                    }
                }
                if(correct&&str_a!=str_b)
                    return true;
            }
        }
        return false;
    }
};
