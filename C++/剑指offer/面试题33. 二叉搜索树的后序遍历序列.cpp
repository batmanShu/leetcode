class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size()<=2) return true;
        return check(postorder,0,postorder.size()-1);
    }
    bool check(vector<int>& postorder, int L, int R){
        if(L>=R) return true;
        int root=postorder[R];
        int mid=L;
        for(;mid<R;mid++)
        {
            if(postorder[mid]>root)
            {
                break;
            }
        }
        int i=mid;
        for(;i<R;i++)
        {
            if(postorder[i]<root) return false;
        }
        return check(postorder,L,mid-1)&&check(postorder,mid,R-1);
    }
};
