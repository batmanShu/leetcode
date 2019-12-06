class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string ret="";
        string prev_str=countAndSay(n-1);
        char cur_ch=prev_str[prev_str.length()-1];
        int count=0;
        for(int i=prev_str.length()-1;i>-1;i--)
        {
            if(cur_ch!=prev_str[i])
            {
                ret=to_string(count)+cur_ch+ret;
                cur_ch=prev_str[i];
                count=0;
            }
            count++;
            if(i==0)
            {
                ret=to_string(count)+cur_ch+ret;
            }
        }
        return ret;
    }
};