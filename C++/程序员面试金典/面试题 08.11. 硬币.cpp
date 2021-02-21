class Solution {
public:
    int waysToChange(int n) {
        vector<int> f(n+1,0);
        f[0]=1;
        int coins[4]={1,5,10,25};
        for(int i=0;i<4;i++)
        {
            int coin=coins[i];
            for(int j=coin;j<=n;j++)
                f[j]=(f[j]+f[j-coin])%1000000007;
        }
        return f[n];
    }
};
