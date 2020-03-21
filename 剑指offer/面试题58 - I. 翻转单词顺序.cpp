class Solution {
public:
    string reverseWords(string s) {
        int k = 0,e = s.size()-1;
        while(s[k] == ' ') k++; // 去掉前面的空格
        while(s[e] == ' ') e--; // 去掉后面的空格
        string tmps = "",ans = "";
        for(int i = k; i <= e; i++)
        {
            if(s[i] != ' ')
                tmps+=s[i];
            else
            {
                while(s[i] == ' ') i++; i--;
                ans+=swapstr(tmps);
                ans+=" "; tmps="";
            }
        }
        ans += swapstr(tmps);
        return swapstr(ans);
    }
    // 交换的单个单词
    string swapstr(string s)
    {
        int i = 0, j = s.size() - 1;
        while(i < j) swap(s[i++],s[j--]);
        return s;
    }
};
