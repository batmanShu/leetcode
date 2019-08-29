/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */
class Solution {
public:
    bool isPalindrome(string s) {
        int start=0;
        int end=s.size()-1;
        while(start<end)
        {
            if(!isValid(s[start]))
            {
                start++;
                continue;
            }
            if(!isValid(s[end]))
            {
                end--;
                continue;
            }
            if(tolower(s[start])==tolower(s[end]))
            {
                start++;
                end--;
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    bool isValid(char c){
        if(c>='a'&&c<='z') return true;
        else if(c>='A'&&c<='Z') return true;
        else if(c>='0'&&c<='9') return true;
        else return false;
    }
};

