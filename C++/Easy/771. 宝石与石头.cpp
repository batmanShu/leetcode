class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ans=0;
        for(int i=0;i<S.size();i++)
        {
            int pos=J.find(S[i]);
            if(pos!=string::npos)
                ans++;
        }
        return ans;
    }
};
