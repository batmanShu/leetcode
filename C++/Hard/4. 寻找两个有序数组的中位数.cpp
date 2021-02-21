class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if(m>n)
        {
            return findMedianSortedArrays(nums2,nums1);
        }
        int Lmax1,Rmin1,Lmax2,Rmin2,c1,c2,lo=0,hi=2*m;
        while(lo<=hi)
        {
            c1=(lo+hi)/2;
            c2=m+n-c1;
            Lmax1=(c1==0)?INT_MIN:nums1[(c1-1)/2];
            Rmin1=(c1==2*m)?INT_MAX:nums1[c1/2];
            Lmax2=(c2==0)?INT_MIN:nums2[(c2-1)/2];
            Rmin2=(c2==2*n)?INT_MAX:nums2[c2/2];
            if(Lmax1>Rmin2)
            {
                hi=c1-1;
            }
            else if(Lmax2>Rmin1)
            {
                lo=c1+1;
            }
            else
            {
                break;
            }
        }
        return (max(Lmax1,Lmax2)+min(Rmin1,Rmin2))/2.0;

    }
};
