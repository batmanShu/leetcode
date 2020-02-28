class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxSlidingWindow;
        if(nums.size()>=k&&k>=1)
        {
            deque<int> index;
            for(int i=0;i<k;i++)
            {
                while(!index.empty()&&nums[i]>nums[index.back()]) index.pop_back();
                index.push_back(i);
            }
            maxSlidingWindow.push_back(nums[index.front()]);
            for(int i=k;i<nums.size();i++)
            {
                while(!index.empty()&&nums[i]>nums[index.back()]) index.pop_back();
                index.push_back(i);
                while(!index.empty()&&index.front()<=(int)(i-k)) index.pop_front();
                maxSlidingWindow.push_back(nums[index.front()]);
            }
        }
        return maxSlidingWindow;
    }
};
