/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        int begin=0,end=numbers.size()-1;
        //int p=findPosition(numbers,target,begin,end);
        for(int j=end;j>0;j--)
        {
            
            for(int i=begin;i<j;i++)
            {
                int result=numbers[i]+numbers[j];
                if(result==target) 
                {
                    ret.push_back(i+1);
                    ret.push_back(j+1);
                    return ret;
                }
                if(result>target) break;//其实还可以考虑最小数那边的情况
                if(result<target) begin++; 
            }
        }
        return [-1,-1];
    }

    //本来想用二分法找到target的位置，但这样就没考虑到负数的情况，因此没用这个函数
    int findPosition(vector<int> numbers,int target,int begin, int end){
        if(begin==end) return begin;
        int i=(end-begin)/2+begin;
        if(target<numbers[i+1]&&target>=numbers[i]) return i;
        if(numbers[i]>target) end=i;
        if(numbers[i]<target) begin=i+1;
        return findPosition(numbers,target,begin,end);
    }
};

