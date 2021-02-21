class Solution {
public:
    int minArray(vector<int>& numbers) {
        int len=numbers.size();
        if(len<1) return -1;
        int left=0,right=len-1;
        if(numbers[left]<numbers[right]) return numbers[left];
        while(right-left>1)
        {
            int middle=(left+right)/2;
            if(numbers[middle]>numbers[right]) left=middle;
            else if(numbers[middle]<numbers[right])right=middle;
            else
            {
                right--;
            }
        }
        return min(numbers[left],numbers[right]);
    }
};
