struct cmp{
    bool operator()(vector<int> pt1,vector<int> pt2){
        double d1=pow(pt1[0],2)+pow(pt1[1],2);
        double d2=pow(pt2[0],2)+pow(pt2[1],2);
        if(d1>d2)
            return true;
        else
            return false;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
        vector<vector<int>> ans;
        for(int i=0;i<points.size();i++)
        {
            pq.push(points[i]);
        }
        for(int i=0;i<K;i++)
        {
            if(!pq.empty())
            {
                ans.push_back(pq.top());
                pq.pop();
            }
        }
        return ans;
    }
};
