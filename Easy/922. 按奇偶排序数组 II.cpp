class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> ans=A;
        int i=0;
        int j=1;
        for(int k=0;k<A.size();k++)
        {
            if(A[k]%2==0)
            {
                ans[i]=A[k];
                i=i+2;
            }
            else
            {
                ans[j]=A[k];
                j=j+2;
            }
        }
        return ans;
    }
};
