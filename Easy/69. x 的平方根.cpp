class Solution{
public:
    int mySqrt(int x) {
        int start = 1;
        int end = x / 2;
        int mid;
        while (start <= end){
            mid = ( start + end ) / 2;
            if (mid == x / mid){
                /// mid * mid == x
                return mid;
            }else if (mid < x / mid && (mid + 1) > x/(mid + 1) ){
                /// mid * mid < x  && (mid + 1) * (mid + 1) > x
                return mid;
            }else if (mid > x / mid){
                end = mid - 1;
            }else {
                start = mid + 1;
            }
        }
        return x;/// x = 0, 1的时候,直接return x
    }
};
