class Solution {
public:
    void reverseWords(vector<char>& s) {
        int begin_ind;
        int end_ind;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
            {
                begin_ind=i;
                break;
            }
        }
        for(int j=s.size()-1;j>=0;j--)
        {
            if(s[j]!=' ')
            {
                end_ind=j;
                break;
            }
        }
        swap_vec(s,begin_ind,end_ind);
        for(int i=begin_ind;i<end_ind;)
        {
            int j=i;
            while(s[j]!=' '&&j!=end_ind)
            {
                j++;
            }
            if(j!=end_ind)
                swap_vec(s,i,j-1);
            else
                swap_vec(s,i,j);
            i=j;
            while(s[i]==' ')
                i++;
        }
    }

    void swap_vec(vector<char>& s,int i,int j) {
        while(i<j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
};
