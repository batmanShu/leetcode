class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int kingcount=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                kingcount++;
            else if(i>0&&nums[i-1]!=0)
            {
                if(nums[i]==nums[i-1]) return false;
                kingcount-=nums[i]-nums[i-1]-1;
                cout<<kingcount<<endl;
                if(kingcount<0) return false;
            }
        }
        return true;
    }
};
