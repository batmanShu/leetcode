class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> res;
        int len=text.size();
        for(int i=0;i<len;i++)
        {
            for(auto word:words)
            {
                if(match(text,i,word))
                {
                    int j=i+word.size()-1;
                    res.push_back({i,j});
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
    bool match(string &text, int i, string word) {
        if(i+word.size()>text.size())
            return false;
        for(int k=0;k<word.size();k++)
        {
            if(text[i+k]!=word[k])
            {
                return false;
            }
        }
        return true;
    }
};
