class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int left=1;
        int right=1;
        int cursum=1;
        while(left<=right&&right<target)
        {
            if(cursum<target)
            {
                right++;
                cursum+=right;
            }
            else if(cursum>target)
            {
                cursum-=left;
                left++;
            }
            else
            {
                vector<int> temp;
                for(int i=left;i<=right;i++)
                {
                    temp.push_back(i);
                }
                res.push_back(temp);
                right++;
                cursum+=right;
            }
        }
        return res;
    }
};
