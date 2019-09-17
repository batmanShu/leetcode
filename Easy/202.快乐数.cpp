/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
class Solution {
public:
    bool isHappy(int n) {
        int result=n;
        vector<int> results;
        results.push_back(n);
        while(1)
        {
            result=computeHappy(result);
            if(result==1) return true;
            for(int i=0;i<results.size();i++)
            {
                if(results[i]==result) return false;
            }
            results.push_back(result);
        }
    }

    int computeHappy(int n){
        int temp=n;
        n=0;
        while(temp!=0)
        {
            int remain=temp%10;
            n=n+pow(remain,2);
            temp=temp/10;
        }
        return n;
    }
};

