class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        words.push_back(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        for(auto str:words)
        {
            if (str==word) return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int len_prefix=prefix.size();
        for(auto str:words)
        {
            int flag=0;
            if(str.size()<len_prefix) continue;
            for(int j=0;j<len_prefix;j++)
            {
                if(prefix[j]!=str[j])
                {
                    flag=1;
                    break;
                } 
            }
            if (flag==0) return true;
        }
        return false;
    }

private:
    vector<string> words;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
