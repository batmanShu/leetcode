class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        for(int i=0;i<calories.size();i++)
        {
            if(i>0)
                calories[i]=calories[i]+calories[i-1];
        }
        int ans=0;
        for(int i=0;i<calories.size();i++)
        {
            int temp;
            if(i+k-1>=calories.size())
                continue;
            else
            {
                if(i>0)
                    temp=calories[i+k-1]-calories[i-1];
                else
                    temp=calories[i+k-1];
            }
            if(temp<lower)
                ans--;
            if(temp>upper)
                ans++;
        }
        return ans;
    }
};
