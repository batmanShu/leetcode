class Solution {
private: 
    unordered_map<int, int> mp;
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int res=0;
        int sum=0;
        mp[0]=1;
        for(int i=0;i<A.size();i++)
        {
            sum+=A[i];
            int remainder=sum%K;
            while(remainder<0)
                remainder+=K;
            if(mp.count(remainder))
            {
                res+=mp[remainder];
                mp[remainder]++;
            }
            else
            {
                mp[remainder]=1;
            }
        }
        return res;
    }
};
