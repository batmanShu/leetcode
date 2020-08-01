class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> pos(nums.size(),0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq0;
        priority_queue<pair<int,int>> pq1;
        vector<int> res(2,0);
        int len=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            pq0.push(make_pair(nums[i][pos[i]],i));
            pq1.push(make_pair(nums[i][pos[i]],i));
        }
        while(pos[pq0.top().second]<nums[pq0.top().second].size())
        {
            pair<int,int> left=pq0.top();
            pair<int,int> right=pq1.top();
            if(right.first-left.first<len)
            {
                res[0]=left.first;
                res[1]=right.first;
                len=res[1]-res[0];
            }
            pos[left.second]++;
            if(pos[left.second]>=nums[left.second].size())
                break;
            pq0.pop();
            pq0.push(make_pair(nums[left.second][pos[left.second]],left.second));
            pq1.push(make_pair(nums[left.second][pos[left.second]],left.second));
        }
        return res;
    }
};
