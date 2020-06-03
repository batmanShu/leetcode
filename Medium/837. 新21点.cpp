class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K==0) return 1;
        double dp[K+W];
        for(int i=N+1;i<K+W;i++)
        {
            dp[i]=0;
        }
        for(int i=K;i<N+1;i++)
        {
            dp[i]=1;
        }
        double s=0;
        for(int i=K;i<K+W;i++)
        {
            s+=dp[i];
        }
        for(int i=K-1;i>=0;i--)
        {
            dp[i]=s/W;
            s+=dp[i];
            s-=dp[i+W];
        }
        return dp[0];
    }
};
