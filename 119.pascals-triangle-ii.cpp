/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1,0);
        if(rowIndex==0)
        {
            result[0]=1;
        }
        else
        {
            vector<int> lastRow;
            lastRow=getRow(rowIndex-1);
            for(int i=0;i<rowIndex+1;i++)
            {
                if(i==0)
                {
                    result[i]=1;
                }
                else if(i==rowIndex)
                {
                    result[i]=1;
                }
                else
                {
                    result[i]=lastRow[i-1]+lastRow[i];
                }
            }
        }
        return result;
        
    }
};

