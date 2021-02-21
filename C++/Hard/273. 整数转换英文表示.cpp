class Solution {
public:
    string numberToWords(int num) {
        if(num==0) return "Zero";
        vector<int> nums;
        string res;
        while(num>0)
        {
            int temp=num%1000;
            num=num/1000;
            nums.push_back(temp);
        }
        if(nums.size()>0) res=smallnumberToWords(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                if(res.size()>0) res=" "+res;
                res=smallnumberToWords(nums[i])+" "+bitwords(i)+res;
            }
            
        }
        return res;
    }
    string smallnumberToWords(int num) {
        if(num==0) return "";
        if(num<20)
        {
            switch(num){
                case 1: return "One";
                case 2: return "Two";
                case 3: return "Three";
                case 4: return "Four";
                case 5: return "Five";
                case 6: return "Six";
                case 7: return "Seven";
                case 8: return "Eight";
                case 9: return "Nine";
                case 10: return "Ten";
                case 11: return "Eleven";
                case 12: return "Twelve";
                case 13: return "Thirteen";
                case 14: return "Fourteen";
                case 15: return "Fifteen";
                case 16: return "Sixteen";
                case 17: return "Seventeen";
                case 18: return "Eighteen";
                case 19: return "Nineteen";
            }
        }
        if(num>=20&&num<=99)
        {
            string s=smallnumberToWords(num%10);
            if(s.size()>0) s=" "+s;
            switch(num/10){
                case 2: return "Twenty"+s;
                case 3: return "Thirty"+s;
                case 4: return "Forty"+s;
                case 5: return "Fifty"+s;
                case 6: return "Sixty"+s;
                case 7: return "Seventy"+s;
                case 8: return "Eighty"+s;
                case 9: return "Ninety"+s;
            }
        }
        string s1=smallnumberToWords(num%100);
        if(s1.size()>0) s1=" "+s1;
        string s=smallnumberToWords(num/100)+" Hundred"+s1;
        return s;
    }
    string bitwords(int i) {
        switch(i){
            case 1: return "Thousand";
            case 2: return "Million";
            case 3: return "Billion";
            case 4: return "Trillion";
        }
        return "";
    }
};
