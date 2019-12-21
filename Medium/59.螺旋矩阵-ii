class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> res_vec;
       if(n==0) return res_vec;
       int res[n][n];
       int cur_dim=n;
       int i=0,j=0;
       int x=0;
       int count;
       while(cur_dim>0)
       {
           j=i;
           count=0;
           x++;
           res[i][j]=x;
           while(count<cur_dim-1)
           {
               x++;
               j++;
               res[i][j]=x;
               count++;
           }
           count=0;
           while(count<cur_dim-1)
           {
               x++;
               i++;
               res[i][j]=x;
               count++;
           }
           count=0;
           while(count<cur_dim-1)
           {
               x++;
               j--;
               res[i][j]=x;
               count++;
           }
           count=0;
           while(count<cur_dim-2)
           {
               x++;
               i--;
               res[i][j]=x;
               count++;
           }
           cur_dim=cur_dim-2;
       }
       for(int m=0;m<n;m++)
       {
           vector<int> temp;
           for(int k=0;k<n;k++)
           {
               temp.push_back(res[m][k]);
           }
           res_vec.push_back(temp);
       }
       return res_vec; 
    }
};
