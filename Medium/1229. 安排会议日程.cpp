class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        vector<int> res;
        int i=0;
        int j=0;
        sort(slots1.begin(),slots1.end());
        sort(slots2.begin(),slots2.end());
        while(i<slots1.size()&&j<slots2.size())
        {
            if(slots1[i][1]-slots1[i][0]<duration)
                i++;
            else if(slots2[j][1]-slots2[j][0]<duration)
                j++;
            else
            {
                vector<int> temp=commonslot(slots1[i],slots2[j]);
                if(temp[1]-temp[0]>=duration)
                {
                    res.push_back(temp[0]);
                    res.push_back(temp[0]+duration);
                    break;
                }
                else
                {
                    if(slots1[i][0]<slots2[j][0])
                        i++;
                    else
                        j++;
                }
            }
        }
        return res;
    }
    vector<int> commonslot(vector<int>& slot1, vector<int>& slot2) {
        int a=max(slot1[0],slot2[0]);
        int b=min(slot1[1],slot2[1]);
        return {a,b}; 
    }
};
