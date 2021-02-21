class Solution {
public:
    int uniquePaths(int m, int n) {
        double bigger=m-1;
        double smaller=n-1;
        if(bigger<smaller)
        {
            bigger=n-1;
            smaller=m-1;
        }
        double p=1;
        while(smaller>0)
        {
            p*=smaller/(bigger+smaller);
            smaller--;
        }
        return (int)(1/p+0.00001);
    }
};
