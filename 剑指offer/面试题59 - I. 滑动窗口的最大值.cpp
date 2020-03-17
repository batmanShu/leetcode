class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        queue<int> q;
        vector<int> res;
        if(nums.size()==0||nums.size()<k) return res;
        for(int i=0;i<nums.size();i++)
        {
            if(q.size()<k)
            {
                q.push(nums[i]);
                while(!dq.empty()&&dq.back()<nums[i]) dq.pop_back();
                dq.push_back(nums[i]);
            }
            else
            {
                res.push_back(dq.front());
                if(q.front()==dq.front()) dq.pop_front();
                q.pop();
                q.push(nums[i]);
                while(!dq.empty()&&dq.back()<nums[i]) dq.pop_back();
                dq.push_back(nums[i]);
            }
        }
        res.push_back(dq.front());
        return res;
    }
};
