/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> number;
        number.push_back(nums[0]);
        for(auto itr0=nums.begin()+1;itr0!=nums.end();itr0++)
        {
            if(number.size()==0)
            {
                number.push_back(*itr0);
            }
            else
            {
                int lengthofnumber=number.size();
                for(auto itr1=number.begin();itr1!=number.end();itr1++)
                {
                    if(*itr1==*itr0)
                    {
                        number.erase(itr1);
                        break;
                    }
                }
                if(number.size()==lengthofnumber)
                {
                    number.push_back(*itr0);
                }
            }
        }
        return number[0];
    }
};

