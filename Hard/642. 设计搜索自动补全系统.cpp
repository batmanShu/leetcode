class AutocompleteSystem {
public:
    string cur;//当前输入的查询字符串
    int idx;//当前输入查询字符在查询字符串的下标
    vector<string> res;//目前所有可能的补全结果，按题目要求排序（热度递减、字典序递增）
    unordered_map<char, map<string, int>> cnt;//以各个字母开头的所有字符串的历史查询次数
    static bool cmp(pair<string, int>& a, pair<string, int>& b){//排序函数
        if(a.second != b.second)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        cur = "";
        idx = 0;
        res.clear();
        cnt.clear();
        for(int i = 0; i < sentences.size(); i++)
            cnt[sentences[i][0]][sentences[i]] = times[i];
    }
    vector<string> input(char c) {
        if(c == '#'){//本此查询完毕，更新cnt，清空缓存量
            cnt[cur[0]][cur]++;
            cur = "";
            idx = 0;
            res.clear();
            return res;
        }
        if(idx == 0){//输入查询字符串的第一个字母
            cur += c;
            idx++;
            //找到所有可能的补全结果
            vector<pair<string, int>> temp;
            for(auto it = cnt[c].begin(); it != cnt[c].end(); it++)
                temp.push_back(*it);
            sort(temp.begin(), temp.end(), cmp);//排序
            for(auto it = temp.begin(); it != temp.end(); it++)
                res.push_back(it->first);
        }
        else{
            auto it = res.begin();
            while(it != res.end()){//去掉res中不可能是补全结果的单词
                if((*it).size() <= idx || (*it)[idx] != c)
                    res.erase(it);
                else
                    it++;
            }
            cur += c;
            idx++;
        }
        //返回res中的前三个
        if(res.size() < 3) 
            return res;
        else
            return vector<string>(res.begin(), res.begin()+3);
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
