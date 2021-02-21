class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            while(i<s.size()&&!isalpha(s[i])&&!isdigit(s[i]))
                i++;
            while(j>=0&&!isalpha(s[j])&&!isdigit(s[j]))
                j--;
            if(i>=j)
                break;
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
