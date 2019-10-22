/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>  secretCount;
        unordered_map<char,int>  guessCount;
        int bulls=0;
        int cows=0;
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
            {
                bulls++;
                continue;
            } 
            else
            {
                if(secretCount.find(secret[i])==secretCount.end()) secretCount[secret[i]]=1;
                else secretCount[secret[i]]++;
                if(guessCount.find(guess[i])==guessCount.end()) guessCount[guess[i]]=1;
                else guessCount[guess[i]]++;
            }
        }
        for(auto itr=guessCount.begin();itr!=guessCount.end();itr++)
        {
            if(secretCount.find(itr->first)!=secretCount.end())
            {
                cows=cows+min(itr->second,secretCount[itr->first]);
            }
        }
   
        string ret=to_string(bulls)+"A"+to_string(cows)+"B";
        return ret;
    }
};
// @lc code=end

