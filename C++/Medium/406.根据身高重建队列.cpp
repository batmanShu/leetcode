class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](const vector<int>&lhs, const vector<int>&rhs){return lhs[0]==rhs[0]? lhs[1]<=rhs[1]:lhs[0]>rhs[0];});
        list<vector<int>> tmp;
        for(int i=0;i<people.size();i++)
        {
            auto pos=tmp.begin();
            advance(pos,people[i][1]);
            tmp.insert(pos,people[i]);
        }
        return vector<vector<int>>(tmp.begin(),tmp.end());
    }
};
