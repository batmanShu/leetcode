class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='+'&&i<s.size()-1)
            {
                if(s[i+1]=='+')
                {
                    string temp=s;
                    temp[i]='-';
                    temp[i+1]='-';
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};
