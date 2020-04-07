class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i=0,j=0;
        if(abbr.length()>word.length()) return false;
        while(i<word.length()&&j<abbr.length())
        {
            if(abbr[j]>='0'&&abbr[j]<='9')
            {
                int temp=abbr[j]-'0';
                if(temp==0) return false;
                j++;
                while(abbr[j]>='0'&&abbr[j]<='9') temp=temp*10+abbr[j++]-'0';
                i+=temp;
                if(i>=word.length()&&j<abbr.length()) return false;
            }
            else
            {
                if(word[i]!=abbr[j]) return false;
                i++;
                j++;
            }
        }
        if(i==word.length()) return true;
        else return false;
    }
};
