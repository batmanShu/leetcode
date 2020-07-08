class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> res;
        if(k==0)
            return res;
        int length=shorter*k;
        int dis=longer-shorter;
        res.push_back(length);
        if(dis!=0)
        {
            for(int i=1;i<=k;i++)
            {
                length+=dis;
                res.push_back(length);
            }
        }
        return res;
    }
};
