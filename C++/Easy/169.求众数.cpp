/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 求众数
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> countMap;//多此一举，其实只要记一个最大count就好
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
            {
                pair<int,int> temp(nums[i],1);
                countMap.insert(temp);
                continue;
            }
            int newelementflag=1;
            for(auto itr=countMap.begin();itr!=countMap.end();itr++)
            {
                if(nums[i]==itr->first)
                {
                    itr->second++;
                    newelementflag=0;
                    break;
                }
            }
            if(newelementflag==1)
            {
                pair<int,int> temp1(nums[i],1);
                countMap.insert(temp1);
            }
        }
        int majorityelement=0;
        for(auto itr=countMap.begin();itr!=countMap.end();itr++)
        {
            if(itr->second>nums.size()/2) 
            {
                majorityelement=itr->first;
            }
        }
        return majorityelement;
    }
};

