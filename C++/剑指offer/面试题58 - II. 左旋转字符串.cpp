class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int len=s.length();
        n=n%len;
        string temp1=s.substr(0,n);
        string temp2=s.substr(n,len-n);
        return temp2+temp1;
    }
};
