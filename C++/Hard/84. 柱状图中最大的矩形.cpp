class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> s;
        int maxarea=0;
        s.push(make_pair(-1,0));
        for(int i=0;i<heights.size();i++)
        {
            int j1=s.top().first;
            int prev_h=s.top().second;
            while(heights[i]<prev_h)
            {
                s.pop();
                int j2=s.top().first;
                maxarea=max(prev_h*(i-j2-1),maxarea);
                j1=s.top().first;
                prev_h=s.top().second;
            }
            s.push(make_pair(i,heights[i]));
        }
        int ind_end=s.top().first+1;
        while(s.size()>=2)
        {
            int h=s.top().second;
            s.pop();
            int j=s.top().first;
            maxarea=max(h*(ind_end-j-1),maxarea);
        }
        return maxarea;
    }
};
