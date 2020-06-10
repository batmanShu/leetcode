class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        long long llower=lower;
        long long lupper=upper;
        long long prev=llower-1;
        vector<string> res;
        if(nums.size()==0)
        {
            string temp=constructstr(llower-1,lupper+1);
            res.push_back(temp);
            return res;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>1+prev)
            {
                string temp=constructstr(prev,nums[i]);
                res.push_back(temp);
            }
            prev=nums[i];
        }
        if(lupper>nums[nums.size()-1])
        {
            string temp=constructstr(nums[nums.size()-1],lupper+1);
            res.push_back(temp);
        }
        return res;
    }
private:
    string constructstr(long long i,long long j){
        string temp=to_string(i+1);
        if(j==i+2)
            return temp;
        temp=temp+"->";
        temp=temp+to_string(j-1);
        return temp;
    }
};
