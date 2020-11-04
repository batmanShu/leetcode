class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int flag=0;
        vector<vector<int>> ans;
        if(intervals.size()==0)
        {
            ans.push_back(newInterval);
            return ans;
        }
        if(newInterval.size()==0)
            return intervals;
        if(newInterval[0]>intervals[intervals.size()-1][1])
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        for(int i=0;i<intervals.size();i++)
        {
            if(flag==0)
            {
                if(newInterval[0]>intervals[i][1])
                    ans.push_back(intervals[i]);
                else
                {
                    vector<int> temp;
                    if(newInterval[0]>=intervals[i][0])
                        temp.push_back(intervals[i][0]);
                    else
                        temp.push_back(newInterval[0]);
                    int j;
                    for(j=i;j<intervals.size();j++)
                    {
                        if(newInterval[1]>intervals[j][1])
                            continue;
                        else
                        {
                            if(newInterval[1]>=intervals[j][0])
                            {
                                temp.push_back(intervals[j][1]);
                                i=j;
                            }
                            else
                            {
                                temp.push_back(newInterval[1]);
                                i=j-1;
                            }
                            ans.push_back(temp);
                            flag=1;
                            break;
                        }
                    }
                    if(j==intervals.size())
                    {
                        temp.push_back(newInterval[1]);
                        i=j;
                        ans.push_back(temp);
                    }
                }
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
