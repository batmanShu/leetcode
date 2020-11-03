class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int flag=0;
        for(int i=1;i<A.size();i++)
        {
            if(A[i]>A[i-1])
            {
                if(flag==0)
                    flag=1;
                else if(flag==2)
                    return false;
            }
            else if(A[i]<A[i-1])
            {
                if(flag==1)
                    flag=2;
                else if(flag==0)
                    return false;
            }
            else
                return false;
        }
        if(flag==2)
            return true;
        else
            return false;
    }
};
