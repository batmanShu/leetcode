class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp());
        return arr;
    }

    struct cmp{   
        bool operator()(int i,int j){
            int ni=numofone(i);
            int nj=numofone(j);
            if(ni<nj)
            {
                return true;
            }
            else if(ni>nj)
            {
                return false;
            }
            else
            {
                return i<j;
            }
        }

        int numofone(int i){
            int ans=0;
            while(i>0){
                ans+=(i&1);
                i=i>>1;
            }
            return ans;
        }
    };

};
