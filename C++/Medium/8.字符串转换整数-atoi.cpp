/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        if(str.size()==0) return 0;
        int sign=1;
        int i=0;
        long int result=0;
        while(i<str.size()&&str[i]==' ') ++i;
        if(isalpha(str[i])) return 0;
        if(str[i]=='+'||str[i]=='-')
        {
            sign=(str[i++]=='+')?1:-1;
        }
        while(i<str.size()&&isdigit(str[i]))
        {
            result=result*10+(int)(str[i++]-'0');
            if(result!=(int)result) return (sign==1)?INT_MAX:INT_MIN;
        }
        return result*sign;
    }
};
// @lc code=end

