class Solution {
public:
    int add(int a, int b) {
        while(b!=0)
        {
            int plus=a^b;
            b=((unsigned int)(a&b))<<1;
            a=plus;
        }
        return a;
    }
};
