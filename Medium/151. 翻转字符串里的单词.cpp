class Solution {
public:
    string reverseWords(string s) {
        int len=s.size();
        if(len==0) return s;
        reverseWordsCore(s,0,len);
        string res="";
        for(int i=0;i<len;)
        {
            if(s[i]==' ') i++;
            else
            {
                int j=i;
                while(j<len&&s[j]!=' ') j++;
                reverseWordsCore(s,i,j);
                if(i<j&&j<=len) res=res+s.substr(i,j-i)+' ';
                i=j;
            }
        }
        if(res.size()>0)
        {
            auto itr=res.end()-1;
            if(*itr==' ') res.erase(itr);
        }
        return res;
    }
    void reverseWordsCore(string &s, int start, int end){
        if(end<=start||end>s.size()) return;
        while(start<end-1)
        {
            swap(s[start],s[end-1]);
            start++;
            end--;
        }
    }
};
