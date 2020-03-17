class Solution {
public:
    int reversePairs(vector<int>& nums) {
        count=0;
        if(nums.size()<2) return count;
        merge_sort(nums);
        return count;
    }
    void merge_sort(vector<int>& nums) {
        int len=nums.size();
        if(len<2)
            return;
        vector<int> subnums1(nums.begin(),nums.begin()+len/2);
        vector<int> subnums2(nums.begin()+len/2,nums.end());
        merge_sort(subnums1);
        merge_sort(subnums2);
        nums=merge(subnums1,subnums2);
    }
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size();
        int l2=nums2.size();
        vector<int> res;
        int i=0,j=0;
        while(i<l1&&j<l2)
        {
            if(nums1[i]<=nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
            }
            else
            {
                count+=l1-i;
                res.push_back(nums2[j]);
                j++;
            }
        }
        if(i<l1)
        {
            res.insert(res.end(),nums1.begin()+i,nums1.end());
        }
        if(j<l2)
        {
            res.insert(res.end(),nums2.begin()+j,nums2.end());
        }
        return res;
    }
private:
    int count;
};
