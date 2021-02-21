class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        vector<vector<int>> widths(matrix[0].size(),vector<int>(matrix.size(),0));
        int maxarea=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='0')
                    continue;
                else
                {
                    if(j>0)
                        widths[j][i]=widths[j-1][i]+1;
                    else
                        widths[j][i]=1;
                }
            }
        }
        for(int i=0;i<matrix[0].size();i++)
        {
            maxarea=max(maxarea,tool(widths[i]));
        }
        return maxarea;
    }
int tool(vector<int>& heights) {
        int res=0;
        stack<pair<int,int>> s;
        for(int i=0;i<heights.size();i++)
        {
            while(!s.empty()&&s.top().second>heights[i])
            {
                int h=s.top().second;
                int ind=s.top().first;
                int temp=h*(i-ind);
                s.pop();
                if(s.empty())
                    temp+=h*ind;
                else
                    temp+=h*(ind-s.top().first-1);
                res=max(res,temp);
            }
            s.push(make_pair(i,heights[i]));
        }
        while(!s.empty())
        {
            int h=s.top().second;
            int ind=s.top().first;
            int temp=h*(heights.size()-ind);
            s.pop();
            if(s.empty())
                temp+=h*ind;
            else
                temp+=h*(ind-s.top().first-1);
            res=max(res,temp);
        }
        return res;
    }
};
