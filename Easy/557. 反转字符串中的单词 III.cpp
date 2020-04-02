class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()) return s;
        int start=0,end=0;
        while(end<s.size())
        {
            if(s[end]==' '&&start!=end)
            {
                reverseStr(start,end-1,s);
                while(end<s.size()&&s[end]==' ') end++;
                start=end;
            }
            end++;
        }
        if(s[end-1]!=' ')
            reverseStr(start,end-1,s);
        return s;
    }
    void reverseStr(int start, int end, string& str) {
        while(start<end)
        {
            swap(str[start],str[end]);
            start++;
            end--;
        }
    }
};
