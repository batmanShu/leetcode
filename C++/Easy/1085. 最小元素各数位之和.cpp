class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int min_val=INT_MAX;
        for(int i=0;i<A.size();i++)
        {
            min_val=min(min_val,A[i]);
        }
        int temp=0;
        while(min_val!=0)
        {
            temp+=min_val%10;
            min_val=min_val/10;
        }
        if(temp&1) return 0;
        else return 1;
    }
};
