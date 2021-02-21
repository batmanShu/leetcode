/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        int len_num1=num1.size();
        int len_num2=num2.size();
        string ret="";
        for(int i=len_num1-1;i>-1;i--)
        {
            int num_i=(int)(num1[i]-'0');
            int c=0;
            string temp_str="";
            for(int j=len_num2-1;j>-1;j--)
            {
                int pos=len_num1-i+len_num2-j-1;
                while(pos>temp_str.size()) temp_str='0'+temp_str;
                int num_j=(int)(num2[j]-'0');
                int product=num_i*num_j+c;
                c=product/10;
                product=product%10;
                int temp=(int)(temp_str[temp_str.size()-pos]-'0')+product;
                temp_str[temp_str.size()-pos]=(char)(temp+'0'); 
            }
            if(c!=0) temp_str=(char)(c+'0')+temp_str;
            if(ret.size()==0) ret=temp_str;
            else
            {
                c=0;
                int k,l;
                for(k=temp_str.size()-1,l=ret.size()-1;k>-1&&l>-1;k--,l--)
                {
                    int temp=(int)(temp_str[k]-'0')+(int)(ret[l]-'0')+c;
                    c=temp/10;
                    temp=temp%10;
                    ret[l]=(char)(temp+'0');
                }
                if(k==-1&&l==-1&&c!=0) ret=(char)(c+'0')+ret;
                else if(k==-1&&l!=-1)
                {
                    while(l!=-1&&c!=0)
                    {
                        int temp=c+(int)(ret[l]-'0');
                        c=temp/10;
                        temp=temp%10;
                        ret[l]=(char)(temp+'0');
                        l--;
                    }
                    if(c!=0) ret=(char)(c+'0')+ret;
                }
                else if(k!=-1&&l==-1)
                {
                    while(k!=-1)
                    {
                        int temp=c+(int)(temp_str[k]-'0');
                        c=temp/10;
                        temp=temp%10;
                        ret=(char)(temp+'0')+ret;
                        k--;
                    }
                    if(c!=0) ret=(char)(c+'0')+ret;
                }
            }
        }
        if(ret.size()!=1)
        {
            auto itr=ret.begin();
            while(*itr=='0')
            {
                ret.erase(itr);//很重要，删除了以后itr会自动指向下一个，不用itr++
                if(itr==ret.end()-1) break;
            }
        }
        return ret;
    }
};
// @lc code=end

