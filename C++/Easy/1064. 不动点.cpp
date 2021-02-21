class Solution {
public:
    int fixedPoint(vector<int>& A) {
        int left=0;
        int right=A.size()-1;
        int res=INT_MAX;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(A[mid]==mid)
            {
                res=min(res,mid);
                right=mid-1;
            }
            else if(A[mid]>mid)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        if(res==INT_MAX)
            return -1;
        return res;
    }
};
