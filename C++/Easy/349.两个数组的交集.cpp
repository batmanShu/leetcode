/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> result;
        int i=0;
        for(int j=0;j<nums2.size();j++)
        {
            cout<<j<<endl;
            for(;i<nums1.size();i++)
            {
                cout<<i<<endl;
                if(nums2[j]<nums1[i])
                {
                    break;
                }
                if(nums2[j]==nums1[i])
                {
                    if(result.size()==0)
                    {
                        result.push_back(nums2[j]);
                        break;
                    }
                    else
                    {
                        if(nums2[j]!=result[result.size()-1]) 
                        {
                            result.push_back(nums2[j]);
                            break;
                        }
                        else
                        {
                            i++;
                            break;
                        }
                    }
                }

            }
        }
        return result;
    }
};
// @lc code=end

