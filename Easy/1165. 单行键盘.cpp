class Solution {
public:
    int calculateTime(string keyboard, string word) {
        for(int i=0;i<26;i++)
        {
            mp[keyboard[i]]=i;
        }
        int ans=0;
        int prev=0;
        for(int i=0;i<word.size();i++)
        {
            ans+=abs(mp[word[i]]-prev);
            prev=mp[word[i]];
        }
        return ans;
    }
private:
    unordered_map<char,int> mp;
};
