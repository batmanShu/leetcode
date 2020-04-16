class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<int> pos1;
        vector<int> pos2;
        for(int i=0;i<words.size();i++)
        {
            if(words[i]==word1)
                pos1.push_back(i);
        }
        for(int i=0;i<words.size();i++)
        {
            if(words[i]==word2)
                pos2.push_back(i);
        }
        int sd=INT_MAX;
        for(int i=0;i<pos1.size();i++)
        {
            for(int j=0;j<pos2.size();j++)
            {
                sd=min(sd,abs(pos1[i]-pos2[j]));
            }
        }
        return sd;
    }
};
