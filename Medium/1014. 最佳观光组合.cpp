class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        vector<int> ai=A;
        vector<int> aj=A;
        int maxi=A[0];
        int maxj=A[A.size()-1]-A.size()+1;
        for(int i=0;i<A.size();i++)
        {
            maxi=max(A[i]+i,maxi);
            ai[i]=maxi;
        }
        for(int j=A.size()-1;j>=0;j--)
        {
            maxj=max(maxj,A[j]-j);
            aj[j]=maxj;
        }
        int res=INT_MIN;
        for(int i=0;i<A.size()-1;i++)
        {
            res=max(res,ai[i]+aj[i+1]);
        }
        return res;
    }
};
