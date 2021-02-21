class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sortednums=nums;
        sort(sortednums.begin(),sortednums.end());
        int i=0,j=nums.size()-1;
        while(i<nums.size()&&nums[i]==sortednums[i]) i++;
        while(j>=0&&nums[j]==sortednums[j]) j--;
        if(i>=j) return 0;
        else
        {
            return j-i+1;
        } 
    }
};
