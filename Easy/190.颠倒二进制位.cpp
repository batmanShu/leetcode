/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
<<<<<<< HEAD
        
=======
        vector<int> bits;
        for(int i=0;i<32;i++)
        {
            bits.push_back(n%2);
            n/=2;
        }
        uint32_t m=0;
        for(int i=0;i<32;i++)
        {
            m=2*m+bits[i];
        }
        return m;
>>>>>>> eb1f4c1074a1063dfe58203d1e9afac15b3223fc
    }
};

