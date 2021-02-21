/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1)) return 1;
        int goodVersion=1;
        int badVersion=n;
        while(true)
        {
            if(badVersion-goodVersion==1) return badVersion;
            int testVersion=(badVersion-goodVersion)/2+goodVersion;//注意int可能存在溢出的问题
            if(isBadVersion(testVersion))
            {
                badVersion=testVersion;
            }
            else
            {
                goodVersion=testVersion;
            }
        }
    }
};
// @lc code=end

