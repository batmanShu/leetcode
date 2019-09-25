/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n,true);
        int count=0;
        for(int i=2;i<n;i++)
        {
            if(primes[i]) count++;
            for(int j=2;i*j<n;j++)
            {
                primes[i*j]=false;
            }
        }
        return count;
    }
};

