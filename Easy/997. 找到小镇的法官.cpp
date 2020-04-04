class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> memo(N+1,1);
        memo[0]=0;
        for(int i=0;i<trust.size();i++)
        {
            memo[trust[i][0]]=0;
        }
        int flag=0;
        int judge=0;
        for(int i=1;i<memo.size();i++)
        {
            if(memo[i]==1)
            {
                if(flag==0)
                {
                    judge=i;
                    flag=1;
                }
                else
                    return -1;
            }
        }
        int count=0;
        for(int i=0;i<trust.size();i++)
        {
            if(trust[i][1]==judge)
                count++;
        }
        if(count==N-1)
            return judge;
        else
            return -1;
    }
};
