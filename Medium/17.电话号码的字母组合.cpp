/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char,string> digit_to_alphabet={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        vector<string> ret;
        if(digits.size()==0) return ret;
        auto itr0=digit_to_alphabet.find(digits[0]);
        for(int j=0;j<itr0->second.size();j++)
        {
            string temp_str;
            temp_str.push_back(itr0->second[j]);
            ret.push_back(temp_str);
        }
        if(digits.size()==1) return ret;
        for(int i=1;i<digits.size();i++)
        {
            vector<string> cur_ret;
            auto itr=digit_to_alphabet.find(digits[i]);
            for(int j=0;j<itr->second.size();j++)
            {
                vector<string> temp=ret;
                for(int k=0;k<temp.size();k++)
                {
                    temp[k]=temp[k]+itr->second[j];
                }
                cur_ret.insert(cur_ret.end(),temp.begin(),temp.end());
            }
            ret=cur_ret;
        }
        return ret;
    }
};
// @lc code=end

