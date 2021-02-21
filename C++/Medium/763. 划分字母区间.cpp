class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        for(int i=0;i<S.size();)
        {
            int pos=S.find_last_of(S[i]);
            ans.push_back(pos+1-i);
            for(int j=i+1;j<pos;j++)
            {
                int new_pos=S.find_last_of(S[j]);
                if(new_pos>pos)
                {
                    ans[ans.size()-1]=ans[ans.size()-1]+new_pos-pos;
                    pos=new_pos;
                }
            }
            i=pos+1;
        }
        return ans;
    }
};
