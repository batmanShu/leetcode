class Solution {
public:
    int findNthDigit(int n) {
        if(n<10) return n;
        int base=1;
        while(n>9*pow(10,base-1)*base)
        {
            n-=9*pow(10,base-1)*base;
            base++;
        }
        int num=pow(10,base-1)+n/base;
        int mod=n%base;
        int temp=pow(10,base-mod);
        if(mod==0) return (num-1)%10;
        else return (num/temp)%10;
    }
};
