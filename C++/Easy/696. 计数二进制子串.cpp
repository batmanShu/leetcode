class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0;
        int dp[2]={0,0};
        int i=0;
        while(i<s.size())
        {
            dp[0]=dp[1];
            dp[1]=1;
            while(i<s.size()&&s[i]==s[i+1])
            {
                dp[1]++;
                i++;
            }
            ans+=min(dp[0],dp[1]);
            i++;
        }
        return ans;
    }
};
