class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name.size()>typed.size())
            return false;
        int i=0;
        int j=0;
        while(i<name.size()&&j<typed.size())
        {
            if(name[i]!=typed[j])
                return false;
            else
            {
                i++;
                j++;
                if(name[i]!=typed[j])
                {
                    while(j<typed.size()&&typed[j]==typed[j-1])
                        j++;
                }
            }
        }
        while(j<typed.size()&&typed[j]==typed[j-1])
            j++;
        return i==name.size()&&j==typed.size();
    }
};
