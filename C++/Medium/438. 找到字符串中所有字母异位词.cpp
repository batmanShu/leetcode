class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int left=0,right=0;
        unordered_map<char,int> needs;
        unordered_map<char,int> window;
        for(auto ch:p)
        {
            needs[ch]++;
        }
        int match=0;
        for(;right<s.size();right++)
        {
            window[s[right]]++;
            if(needs.count(s[right]))
            {
                if(window[s[right]]==needs[s[right]]) match++;
            }
            while(match==needs.size())
            {
                if(right-left==p.size()-1) res.push_back(left);
                if(needs.count(s[left])) 
                {
                    window[s[left]]--;
                    if(window[s[left]]<needs[s[left]]) match--;
                }
                left++;
            }
        }
        return res;
    }
};
