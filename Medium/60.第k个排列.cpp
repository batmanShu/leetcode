class Solution {
private:
    list<char> ls;
    char get_ls_k(int k){
        auto itr=ls.begin();
        while(k>0)
        {
            itr++;
            k--;
        }
        char ret=*itr;
        ls.erase(itr);
        return ret;
    }
public:
    string getPermutation(int n, int k) {
        int m=1;
        int fac_n=factorial(n-1);
        int count[n];
        int N=n;
        int c=0;
        int j=0;
        n=n-1;
        while(1)
        {
            k=k-fac_n;
            if(k>0)
            {
                c++;
                continue;
            }
            else if(k<=0)
            {
                k=k+fac_n;
                count[j++]=c; 
                c=0;
                n=n-1;
                fac_n=factorial(n);
            }
            if(j>=N-1) break;
        }
        count[N-1]=0;
        for(int i=1;i<=N;i++)
        {
            ls.push_back(48+i);
        }
        string res="";
        for(int i=0;i<N;i++)
        {
            cout<<count[i]<<endl;
            res=res+get_ls_k(count[i]);
        }
        return res;

    }
    int factorial(int x){
        int res=1;
        while(x>0)
        {
            res=res*x;
            x--;
        }
        return res;
    }
};
