class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==0) return vector<int> {0};
        vector<int> res={0,1};
        for(int i=2;i<=n;i++)
        {
            int l=res.size();
            for(int j=l-1;j>=0;j--)
            {
                res.push_back(res[j]+pow(2,i-1));
            }
        }
        return res;
    }
};
