/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n==1) return {"()"};
        set<string> ret_set;
        vector<string> ret;
        int i=1,j=n-1;
        for(;i<n;++i,--j)
        {
            vector<string> vec_i=generateParenthesis(i);
            vector<string> vec_j=generateParenthesis(j);
            for(int k=0;k<vec_i.size();++k)
            {
                for(int l=0;l<vec_j.size();++l)
                {
                    string temp=vec_i[k]+vec_j[l];
                    ret_set.insert(temp);
                }
            }
        }
        vector<string> vec_prev=generateParenthesis(n-1);
        for(int m=0;m<vec_prev.size();++m)
        {
            string temp2="("+vec_prev[m]+")";
            ret_set.insert(temp2);
        }
        for(auto itr=ret_set.begin();itr!=ret_set.end();itr++)
        {
            ret.push_back(*itr);
        }
        return ret;
    }
};
// @lc code=end

