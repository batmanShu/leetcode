class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> res(2,0);
        int number=0;
        for(auto num:nums)
        {
            number=num^number;
        }
        int pos=number&-(number);
        for(auto num:nums)
        {
            if(num&pos) res[0]=res[0]^num;
            else res[1]=res[1]^num;
        }
        return res;
    }
};
