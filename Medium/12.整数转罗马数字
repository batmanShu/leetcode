class Solution {
public:
    string intToRoman(int num) {
        string ret="";
        int digit=1;
        while(num!=0)
        {
            string temp=bitToRoman(num%10,digit++);
            ret=temp+ret;
            num=num/10;
        }
        return ret;
    }
    string bitToRoman(int bit,int digit){
        string temp="";
        if(digit==1)
        {
            if(bit==4) return "IV";
            else if(bit==9) return "IX";
            else if(bit>=5) 
            {
                for(int i=0;i<bit-5;i++)
                {
                    temp=temp+"I";
                }
                return "V"+temp;

            }
            else
            {
                for(int i=0;i<bit;i++)
                {
                    temp=temp+"I";
                }
                return temp;
            }
        }
        else if(digit==2)
        {
            if(bit==9) return "XC";
            else if(bit==4) return "XL";
            else if(bit>=5) 
            {
                for(int i=0;i<bit-5;i++)
                {
                    temp=temp+"X";
                }
                return "L"+temp;

            }
            else
            {
                for(int i=0;i<bit;i++)
                {
                    temp=temp+"X";
                }
                return temp;
            }
        }
        else if(digit==3)
        {
            if(bit==9) return "CM";
            else if(bit==4) return "CD";
            else if(bit>=5)
            {
                for(int i=0;i<bit-5;i++)
                {
                    temp=temp+"C";
                }
                return "D"+temp;

            } 
            else
            {
                for(int i=0;i<bit;i++)
                {
                    temp=temp+"C";
                }
                return temp;
            }
        }
        else
        {
            for(int i=0;i<bit;i++)
            {
                temp=temp+"M";
            }
            return temp;
        }
    }
};
