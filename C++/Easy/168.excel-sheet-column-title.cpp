/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */
class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while(n>=1)
        {
            int remain=n%26;
            if(remain==0) 
            {
                remain=26;
                n=n-1;                         //注意这不是一个满了以后就会进一位的问题，满了以后会停留，再加1才会前后位同时进1
            }
            char temp=64+remain;
            result.push_back(temp);
            if(n==26) break;
            n=n/26;
        }
        int len=result.length();
        for(int i=0;i<len/2;i++)
        {
            char temp1=result[i];
            result[i]=result[len-i-1];
            result[len-i-1]=temp1;
        }
        return result;
    }
};

