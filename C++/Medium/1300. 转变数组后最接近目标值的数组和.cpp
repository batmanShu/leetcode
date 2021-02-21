class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<int> presum(n+1,0);
        for(int i=1;i<n+1;i++)
        {
            presum[i]=presum[i-1]+arr[i-1];
        }
        int ans=0;
        int r=arr[n-1];
        int diff=target;
        for(int i=1;i<=r;i++)
        {
            auto iter = lower_bound(arr.begin(), arr.end(), i);
            int cur = presum[iter - arr.begin()] + (arr.end() - iter) * i;
            if (abs(cur - target) < diff) {
                ans = i;
                diff = abs(cur - target);
            }
        }
        return ans;
    }
};
