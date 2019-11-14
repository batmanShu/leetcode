class Solution {
public:
    int romanToInt(string s) {
        long int ret=0;
        map<string,int> romanintpair={{"I",1},{"V",5},{"X",10},{"L",50},{"C",100},{"D",500},{"M",1000}};
        for(int i=s.size()-1;i>-1;i--)
        {
            long int temp=0;
            string temp_str;
            temp_str=s[i];
            auto iter=romanintpair.find(temp_str);
            temp=iter->second;
            if(i-1==-1) 
            {
                ret=ret+temp;
                break;
            }
            if(s[i]=='V')
            {
                if(s[i-1]=='I')
                {
                    --i;
                    temp=4;
                }
            }
            else if(s[i]=='X')
            {
                if(s[i-1]=='I')
                {
                    --i;
                    temp=9;
                }
            }
            else if(s[i]=='L')
            {
                if(s[i-1]=='X')
                {
                    --i;
                    temp=40;
                }
            }
            else if(s[i]=='C')
            {
                if(s[i-1]=='X')
                {
                    --i;
                    temp=90;
                }
            }
            else if(s[i]=='D')
            {
                if(s[i-1]=='C')
                {
                    --i;
                    temp=400;
                }
            }
            else if(s[i]=='M')
            {
                if(s[i-1]=='C')
                {
                    --i;
                    temp=900;
                }
            }
            ret=ret+temp;
            
        }
        return ret;
    }
};
