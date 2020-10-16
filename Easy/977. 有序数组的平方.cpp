class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int left=0;
        int right=A.size()-1;
        vector<int> ans;
        while(left<=right)
        {
            int num_l=abs(A[left]);
            int num_r=abs(A[right]);
            if(num_l>num_r)
            {
                ans.push_back(num_l*num_l);
                left++;
            }
            else
            {
                ans.push_back(num_r*num_r);
                right--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
