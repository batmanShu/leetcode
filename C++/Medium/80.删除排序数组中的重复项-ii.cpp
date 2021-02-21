class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        auto itr=nums.begin();
        int cur=*itr;
        int count=0;
        while(itr!=nums.end())
        {
            if(*itr==cur) count++;
            else
            {
                cur=*itr;
                count=1;
            }
            if(count==3)
            {
                nums.erase(itr);
                count=2;
            }
            else itr++;
        }
        return nums.size();
    }
};
