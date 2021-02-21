class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int,int>> s;
        for(int i=T.size()-1;i>=0;i--)
        {
            if(s.empty())
            {
                s.push(make_pair(T[i],i));
                T[i]=0;
            }
            else
            {
                while(!s.empty()&&s.top().first<=T[i]) s.pop();
                if(s.empty())
                {
                    s.push(make_pair(T[i],i));
                    T[i]=0;
                }
                else
                {
                    int temp=T[i];
                    T[i]=s.top().second-i;
                    s.push(make_pair(temp,i));
                }
            }
        }
        return T;
    }
};
