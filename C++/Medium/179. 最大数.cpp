class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        quicksort(nums,0,nums.size()-1);
        for(int i=0;i<nums.size();i++)
        {
            res=res+to_string(nums[i]);
        }
        if(res[0]=='0') res="0";
        return res;
    }
    void quicksort(vector<int>& nums, int begin, int end){
        if(end<=begin) return;
        int i=begin;
        int j=end;
        int baseval=nums[begin];
        while(i<j)
        {
            while(i<j&&isless(nums[j],baseval)>=0) j--;
            while(i<j&&isless(nums[i],baseval)<=0) i++;
            if(i<j) swap(nums[i],nums[j]);
        }
        swap(nums[begin],nums[i]);
        quicksort(nums,begin,i-1);
        quicksort(nums,i+1,end);
    }
    int isless(int a, int b){
        if(a==0&&b==0) return 0;
        if(a==0) return 1;
        if(b==0) return -1; 
        int tempa=a;
        int tempb=b;
        int counta=0;
        int countb=0;
        while(tempa)
        {
            counta++;
            tempa=tempa/10;
        }
        while(tempb)
        {
            countb++;
            tempb=tempb/10;
        }
        long long ab=a*pow(10,countb)+b;
        long long ba=b*pow(10,counta)+a;
        if(ab>ba) return -1;
        else if(ab<ba) return 1;
        else return 0;
    }
};
