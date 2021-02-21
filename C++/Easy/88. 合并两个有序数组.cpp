class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(m<nums1.size())
        {
            auto itr=nums1.end()-1;
            nums1.erase(itr);
        }
        cout<<nums1.size()<<endl;
        mergecore(nums1,m,nums2,n);
    }
    void mergecore(vector<int>& nums1, int m, vector<int>& nums2, int n){
        if(m==0)
        {
            nums1.insert(nums1.end(),nums2.begin()+nums2.size()-n,nums2.end());
            return;
        }
        if(n==0) return;
        if(nums1[nums1.size()-m]>nums2[nums2.size()-n])
        {
            nums1.insert(nums1.begin()+nums1.size()-m,nums2[nums2.size()-n]);
            mergecore(nums1,m,nums2,n-1);
        }
        else
        {
            mergecore(nums1,m-1,nums2,n);
        }
    }
};
