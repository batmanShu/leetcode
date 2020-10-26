class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sortednums(nums);
        sort(sortednums.begin(),sortednums.end());
        unordered_map<int,int> mp;
        for(int i=0;i<sortednums.size();i++)
        {
            if(i==0)
                mp[sortednums[i]]=i;
            else
            {
                if(sortednums[i]==sortednums[i-1])
                    continue;
                else
                {
                    mp[sortednums[i]]=i;
                }
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=mp[nums[i]];
        }
        return nums;
    }
};
