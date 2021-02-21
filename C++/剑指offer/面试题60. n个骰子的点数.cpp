class Solution {
public:
    vector<double> twoSum(int n) {
        vector<int> res(5*n+1,0);
        vector<double> res_d;
        throwdice(res,n,0,0);
        for(auto re:res)
        {
            double temp=re/(double)(pow(6,n));
            res_d.push_back(temp);
        }
        return res_d;
    }
    void throwdice(vector<int>& res, int n, int cursum, int ind){
        if(ind==n) 
        {
            res[cursum-n]++;
            return;
        }
        throwdice(res,n,cursum+1,ind+1);
        throwdice(res,n,cursum+2,ind+1);
        throwdice(res,n,cursum+3,ind+1);
        throwdice(res,n,cursum+4,ind+1);
        throwdice(res,n,cursum+5,ind+1);
        throwdice(res,n,cursum+6,ind+1);
    }
};
