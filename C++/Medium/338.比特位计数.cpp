class Solution {
public:
    vector<int> countBits(int num) {
        if(num<1) return {0};
        if(num==1) return {0,1};
        vector<int> ret(num+1,0);
        ret[0]=0;
        ret[1]=1;
        for(int i=2;i<num+1;i++)
        {
            ret[i]=ret[i&i-1]+1;
        }
        return ret;
    }
};
