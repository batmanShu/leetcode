class Solution {
public:
    string minNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(),nums.end(),compare);
        for(auto num:nums)
        {
            res=res+to_string(num);
        }
        return res;
    }
    static bool compare(int a, int b) {
        string ab=to_string(a)+to_string(b);
        string ba=to_string(b)+to_string(a);
        return ab<ba;
    }
};
