struct Tries {
    char c;
    bool isword;
    int ind;
    vector<Tries*> next;
    Tries(char _c,bool _isword=false,int _ind=-1):c(_c),isword(_isword),ind(_ind){
        next=vector<Tries*>(26,nullptr);
    }
};
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        root=new Tries('*');
        for(int j=0;j<words.size();j++)
        {
            string word=words[j];
            Tries* node=root;
            if(word.size()==0)
            {
                root->ind=j;
                root->isword=true;
            }
            for(int i=0;i<word.size();i++)
            {
                if(node->next[word[i]-'a']==nullptr)
                {
                    Tries* newnode=new Tries(word[i]);
                    node->next[word[i]-'a']=newnode;

                }
                node=node->next[word[i]-'a'];
                if(i==word.size()-1)
                {
                    node->isword=true;
                    node->ind=j;
                }
            }
        }
        for(int j=0;j<words.size();j++)
        {
            string word=words[j];
            for(int i=0;i<=word.size();i++)
            {
                if(i&&ispalindrome(word,0,i-1))
                {
                    int m=findwordinTries(word,i,word.size()-1);
                    if(m!=-1&&m!=j)
                    {
                        ans.push_back({m,j});
                    }
                }
                if(ispalindrome(word,i,word.size()-1))
                {
                    int m=findwordinTries(word,0,i-1);
                    if(m!=-1&&m!=j)
                    {
                        ans.push_back({j,m});
                    }
                }
            }
        }
        return ans;
    }

private:
    bool ispalindrome(const string& str, int left, int right) {
        if(left>right)
            return true;
        while(left<right)
        {
            if(str[left]!=str[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    int findwordinTries(const string& str, int left, int right) {
        Tries* node=root;
        for(int i=right;i>=left;i--)
        {
            if(node->next[str[i]-'a']!=nullptr)
            {
                node=node->next[str[i]-'a'];
            }
            else
            {
                return -1;
            }
        }
        return node->ind;
    }

    Tries* root;
};
