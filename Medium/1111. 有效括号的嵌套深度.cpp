class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        int left_num=0;
        for(int i=0;i<seq.size();i++)
        {
            if(seq[i]=='(')
            {
                left_num++;
                res.push_back(left_num%2);
            }
            else
            {
                res.push_back(left_num%2);
                left_num--;
            }
        }
        return res;
    }
};
