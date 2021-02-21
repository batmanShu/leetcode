class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()<1) return -1;
        int bitSum[31]={0};
        for(int i=0;i<nums.size();i++)
        {
            int bitMask=1;
            for(int j=30;j>=0;j--)
            {
                int bit=nums[i]&bitMask;
                if(bit!=0) bitSum[j]++;
                bitMask=bitMask << 1;
            }
        }
        int result=0;
        for(int i=0;i<31;i++)
        {
            result=result<<1;
            result+=bitSum[i]%3;
        }
        return result;
    }
};
