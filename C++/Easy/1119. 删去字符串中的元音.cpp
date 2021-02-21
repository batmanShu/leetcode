class Solution {
public:
    string removeVowels(string S) {
        for(auto itr=S.begin();itr!=S.end();)
        {
            if(*itr=='a'||*itr=='e'||*itr=='i'||*itr=='o'||*itr=='u')
                S.erase(itr);
            else
                itr++;
        }
        return S;
    }
};
