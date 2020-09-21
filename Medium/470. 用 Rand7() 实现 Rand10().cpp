// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int a=rand7();
        while(a==4)
            a=rand7();
        int flag=a>4?1:0;
        int b=rand7();
        while(b>5)
            b=rand7();
        int ans;
        if(flag)
            ans=11-b;
        else
            ans=b;
        return ans;
    }
};
