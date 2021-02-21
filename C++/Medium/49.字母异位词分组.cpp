class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> ma;
        vector<vector<string>> res;
        for(auto str:strs)
        {
            string temp=str;
            sort(temp.begin(),temp.end());
            ma[temp].push_back(str);
        }
        for(auto m:ma)
        {
            res.push_back(m.second);
        }
        return res;
    }
};
