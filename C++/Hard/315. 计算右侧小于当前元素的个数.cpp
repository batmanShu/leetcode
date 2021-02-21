class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> counts;
        vector<int> sortednums;
        reverse(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(sortednums.size()==0)
            {
                sortednums.push_back(nums[i]);
                counts.push_back(0);
            }
            else
            {
                int j;
                for(j=sortednums.size()-1;j>=0;j--)
                {
                    if(sortednums[j]<nums[i])
                    {
                        counts.push_back(j+1);
                        sortednums.insert(sortednums.begin()+j+1,nums[i]);
                        break;
                    }
                }
                if(j==-1)
                {
                    counts.push_back(0);
                    sortednums.insert(sortednums.begin(),nums[i]);
                }
            }
        }
        reverse(counts.begin(),counts.end());
        return counts;
    }
};
