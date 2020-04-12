class Solution {
public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        vector<double> res;
        vector<double> dstart1(2,0);
        vector<double> dend1(2,0);
        vector<double> dstart2(2,0);
        vector<double> dend2(2,0);
        dstart1[0]=start1[0];
        dstart1[1]=start1[1];
        dend1[0]=end1[0];
        dend1[1]=end1[1];
        dstart2[0]=start2[0];
        dstart2[1]=start2[1];
        dend2[0]=end2[0];
        dend2[1]=end2[1];
        double x,y;
        if(dstart1[0]==dend1[0])
        {
            if(dstart2[0]==dend2[0])
            {
                if(dstart1[0]==dstart2[0])//重合
                {
                    if(isinsection(dstart1,dend1,dstart2)&&isinsection(dstart1,dend1,dend2))//线段1包含线段2
                    {
                        return dstart2<dend2?dstart2:dend2;
                    }
                    else if(isinsection(dstart1,dend1,dstart2))
                    {
                        if(isinsection(dstart2,dend2,dstart1))
                        {
                            return dstart1<dstart2?dstart1:dstart2;
                        }
                        else
                        {
                            return dend1<dstart2?dend1:dstart2;
                        }
                    }
                    else if(isinsection(dstart1,dend1,dend2))
                    {
                        if(isinsection(dstart2,dend2,dstart1))
                        {
                            return dstart1<dend2?dstart1:dend2;
                        }
                        else
                        {
                            return dend1<dend2?dend1:dend2;
                        }
                    }
                    else
                    {
                        return res;
                    }
                }
                else//平行
                {
                    return res;
                }
            }
            else
            {
                x=dstart1[0];
                y=(dend2[1]-dstart2[1])/(dend2[0]-dstart2[0])*(x-dstart2[0])+dstart2[1];
                vector<double> p={x,y};
                if(isinsection(dstart2,dend2,p)&&isinsection(dstart1,dend1,p))
                {
                    return p;
                }
                else
                {
                    return res;
                }
            }
        }
        if(dstart2[0]==dend2[0])
        {
            x=dstart2[0];
            y=(dend1[1]-dstart1[1])/(dend1[0]-dstart1[0])*(x-dstart1[0])+dstart1[1];
            vector<double> p={x,y};
            if(isinsection(dstart2,dend2,p)&&isinsection(dstart1,dend1,p))
            {
                return p;
            }
            else
            {
                return res;
            }
        }
        double k1=(dend1[1]-dstart1[1])/(dend1[0]-dstart1[0]);
        double k2=(dend2[1]-dstart2[1])/(dend2[0]-dstart2[0]);
        if(k1==k2)//平行
        {
            if(k1*(dstart2[0]-dstart1[0])+dstart1[1]==dstart2[1])
            {
                if(isinsection(dstart1,dend1,dstart2)&&isinsection(dstart1,dend1,dend2))//线段1包含线段2
                {
                    return dstart2<dend2?dstart2:dend2;
                }
                else if(isinsection(dstart1,dend1,dstart2))
                {
                    if(isinsection(dstart2,dend2,dstart1))
                    {
                        return dstart1<dstart2?dstart1:dstart2;
                    }
                    else
                    {
                        return dend1>dstart2?dend1:dstart2;
                    }
                }
                else if(isinsection(dstart1,dend1,dend2))
                {
                    cout<<3<<endl;
                    if(isinsection(dstart2,dend2,dstart1))
                    {
                        return dstart1<dend2?dstart1:dend2;
                    }
                    else
                    {
                        return dend1<dend2?dend1:dend2;
                    }
                }
                else
                {
                    return res;
                }
            }
            else
            {
                return res;
            }
        }
        else
        {
            x=(dstart2[1]-dstart1[1]-k2*dstart2[0]+k1*dstart1[0])/(k1-k2);
            y=k1*(x-dstart1[0])+dstart1[1];
            cout<<x<<y<<endl;
            vector<double> p={x,y};
            if(isinsection(dstart2,dend2,p)&&isinsection(dstart1,dend1,p))
            {
                return p;
            }
            else
            {
                return res;
            }
        }
    }
    bool isinsection(vector<double>& start, vector<double>& end, vector<double>& p) {
        if((p[0]>=start[0]-1e-7&&p[0]<=end[0]+1e-7&&p[1]>=start[1]-1e-7&&p[1]<=end[1]+1e-7)||(p[0]>=end[0]-1e-7&&p[0]<=start[0]+1e-7&&p[1]>=end[1]-1e-7&&p[1]<=start[1]+1e-7)||(p[0]<=start[0]+1e-7&&p[0]>=end[0]-1e-7&&p[1]>=start[1]-1e-7&&p[1]<=end[1]+1e-7)||(p[0]>=start[0]-1e-7&&p[0]<=end[0]+1e-7&&p[1]<=start[1]+1e-7&&p[1]>=end[1]-1e-7)) return true;
        return false;
    }
};
