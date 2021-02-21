class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        if(S.length()==0) return S;
        vector<int> arr(S.length(),0);
        for(int i=0;i<S.size();i++)
        {
            for(int k=0;k<words.size();k++)
            {
                auto p=S.find(words[k],i);
                if(p!=string::npos)
                {
                    for(int j=0;j<words[k].size();j++)
                    {
                        arr[p+j]=1;
                    }
                }
            }
        }
        string res="";
        if(arr[0]==1)
            res+="<b>";
        res+=S[0];
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i-1]==0&&arr[i]==1)
                res+="<b>";
            else if(arr[i-1]==1&&arr[i]==0)
                res+="</b>";
            res+=S[i];
        }
        if(arr[arr.size()-1]==1) res+="</b>";
        return res;
    }
};
