class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size()!=popped.size()) return false;
        stack<int> s;
        int i=0,j=0;
        for(;i<pushed.size();i++)
        {
            s.push(pushed[i]);
            while(j<popped.size()&&!s.empty()&&s.top()==popped[j]) 
            {
                j++;
                s.pop();
            }
        }
        if(s.empty()) return true;
        return false;
    }
};
