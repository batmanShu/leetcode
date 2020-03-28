class Solution {

class TrieNode {
    TrieNode* children[26];
public:
    int count=0;
    TrieNode(){
        for(int i=0;i<26;i++)
            children[i]=nullptr;
    }
    TrieNode* get(char c){
        if(children[c-'a']==nullptr)
        {
            TrieNode* cur=new TrieNode();
            children[c-'a']=cur;
            count++;
        }
        return children[c-'a'];
    }
};
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode* trie=new TrieNode();
        unordered_map<TrieNode*,int> mp;
        for(int i=0;i<words.size();i++)
        {
            string word=words[i];
            TrieNode* cur=trie;
            for(int j=word.size()-1;j>=0;j--)
            {
                cur=cur->get(word[j]);
            }
            mp[cur]=i;
        }
        int ans = 0;
        for (auto& [node, idx] : mp) {
            if (node->count == 0) {
                ans += words[idx].length() + 1;
            }
        }
        return ans;
    }
};
