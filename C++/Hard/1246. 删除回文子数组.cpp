class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int arr_len=arr.size();
        vector<vector<int>> dp(arr_len,vector<int>(arr_len,0));
        for(int i=0;i<arr_len;i++)
        {
            dp[i][i]=1;
        }
        for(int i=0;i<arr_len-1;i++)
        {
            if(arr[i]==arr[i+1])
                dp[i][i+1]=1;
            else
                dp[i][i+1]=2;
        }
        for(int len=3;len<=arr_len;len++)
        {
            for(int i=0;i<arr_len-len+1;i++)
            {
                if(arr[i]==arr[i+len-1])
                    dp[i][i+len-1]=dp[i+1][i+len-2];
                else
                    dp[i][i+len-1]=len;
                for(int j=0;j<len-1;j++)
                {
                    dp[i][i+len-1]=min(dp[i][i+len-1],dp[i][i+j]+dp[i+j+1][i+len-1]);
                }
            }
        }
        return dp[0][arr_len-1];
    }
};
