class Solution {
public:
    int dayOfYear(string date) {
        int res=0;
        int y=atoi(date.substr(0,4).c_str());
        int m=atoi(date.substr(5,2).c_str());
        int d=atoi(date.substr(8,2).c_str());
        if((y-2000)%4==0&&y!=1900)
        {
            for(int i=1;i<m;i++)
            {
                res+=daysOfLeapMonth(i);
            }
            res+=d;
        }
        else
        {
            for(int i=1;i<m;i++)
            {
                res+=daysOfMonth(i);
            }
            res+=d;
        }
        return res;
    }
    int daysOfMonth(int m){
        switch(m){
            case 1: return 31;
            case 2: return 28;
            case 3: return 31;
            case 4: return 30;
            case 5: return 31;
            case 6: return 30;
            case 7: return 31;
            case 8: return 31;
            case 9: return 30;
            case 10: return 31;
            case 11: return 30;
            case 12: return 31;
            default: return 0;
        }
    }
    int daysOfLeapMonth(int m){
        switch(m){
            case 1: return 31;
            case 2: return 29;
            case 3: return 31;
            case 4: return 30;
            case 5: return 31;
            case 6: return 30;
            case 7: return 31;
            case 8: return 31;
            case 9: return 30;
            case 10: return 31;
            case 11: return 30;
            case 12: return 31;
            default: return 0;
        }
    }
};
