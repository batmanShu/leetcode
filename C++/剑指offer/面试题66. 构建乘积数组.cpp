class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int product=1;
        for(auto num:a)
        {
            product*=num;
        }
        vector<int> res;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=0)
            {
                res.push_back(product/a[i]);
            }
            else
            {
                int temp=1;
                for(int j=0;j<a.size();j++)
                {
                    if(j!=i) temp*=a[j];
                }
                res.push_back(temp);
            }
        }
        return res;
    }
};
