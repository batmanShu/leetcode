class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<int> rooms;//存储会议室开始空闲的时间
        for(auto interval:intervals)
        {
            if(rooms.empty()) rooms.push_back(interval[1]);
            else
            {
                int flag=0;//看这个会议能否找到之前已有的会议室开会，0代表不能
                for(int i=0;i<rooms.size();i++)
                {
                    if(interval[0]>=rooms[i])
                    {
                        rooms[i]=interval[1];//更新会议室开始空闲时间
                        flag=1;
                        break;
                    }
                }
                if(flag==0) rooms.push_back(interval[1]);
            }
        }
        return rooms.size();
    }
};
