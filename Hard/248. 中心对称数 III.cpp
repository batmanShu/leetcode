class Solution {
public:
    bool compare(string& a, string& b) {
        if(a.size()!=b.size()) return a.size()>b.size();
        return a>=b;
    }
    bool check(string& s, string& low, string& high) {
        return compare(s,low)&&compare(high,s);
    }
    int strobogrammaticInRange(string low, string high) {
        if(low!=high&&compare(low,high)) return 0;
        int res=0;
        queue<string> q;
        q.push("");
        q.push("0");
        q.push("1");
        q.push("8");
        while(!q.empty())
        {
            string curs=q.front();
            q.pop();
            if(curs.size()>=low.size()&&curs.size()<=high.size())
            {
                if(curs[0]!='0'&&check(curs,low,high)) res++;
                else if(curs=="0"&&check(curs,low,high)) res++;
            }
            if(curs.size()>high.size()) continue;
            for(int i=0;i<5;i++)
            {
                string s=dl[i]+curs+dr[i];
                if(s.size()<=high.size()) q.push(s);
            }
        }
        return res;
    }
private:
    char dl[5]={'0','1','8','6','9'};
    char dr[5]={'0','1','8','9','6'};
};
