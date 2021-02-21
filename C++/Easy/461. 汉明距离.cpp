class Solution {
public:
    int hammingDistance(int x, int y) {
        int res=0;
        int temp=x^y;
        while(temp)
        {
            res+=temp&1;
            temp=temp>>1;
        }
        return res;
    }
};
