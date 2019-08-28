/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows==0)
        {
            return result;
        }
        if(numRows==1)
        {
            vector<int> temp;
            temp.push_back(1);
            result.push_back(temp);
        }
        else
        {
            int lastnumRows;
            lastnumRows=numRows-1;
            result=generate(lastnumRows);
            vector<int> currentVector;
            vector<int> lastVector;
            lastVector=result[lastnumRows-1];
            for(int i=0;i<numRows;i++)
            {
                if(i==0) 
                {
                    currentVector.push_back(1);
                }
                else if(i==numRows-1)
                {
                    currentVector.push_back(1);
                }
                else
                {
                    currentVector.push_back(lastVector[i-1]+lastVector[i]);
                }
            }
            result.push_back(currentVector);
        }
        
        return result;
    }
};

