class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        while(s[s.size()-1]==' ') s.pop_back();
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ') count=0;
            else count++;
        }
        return count;
    }
};
