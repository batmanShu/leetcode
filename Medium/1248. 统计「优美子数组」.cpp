class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> oddind;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&1)
            {
                oddind.push_back(i);
            }
        }
        if(oddind.size()<k)
            return 0;
        int res=0;
        int i=0,j=k-1;
        while(j<oddind.size())
        {
            if(i==0&&j==oddind.size()-1)
            {
                res+=(oddind[i]-0+1)*(nums.size()-oddind[j]);
            }
            else if(i==0)
            {
                res+=(oddind[i]-0+1)*(oddind[j+1]-oddind[j]);
            }
            else if(j==oddind.size()-1)
            {
                res+=(oddind[i]-oddind[i-1])*(nums.size()-oddind[j]);
            }
            else
            {
                res+=(oddind[i]-oddind[i-1])*(oddind[j+1]-oddind[j]);
            }
            i++;
            j++;
        }
        return res;
    }
};
