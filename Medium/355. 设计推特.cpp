class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        followlist.clear();
        tweets_pool.clear();
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets_pool.push_back(make_pair(userId,tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> news;
        auto follow=followlist[userId];
        for(int i=tweets_pool.size()-1;i>=0;i--)
        {
            if(news.size()==10) break;
            if(tweets_pool[i].first==userId)
            {
                news.push_back(tweets_pool[i].second);
                continue;
            }
            auto itr=follow.find(tweets_pool[i].first);
            if(itr!=follow.end())
            {
                news.push_back(tweets_pool[i].second);
            }
        }
        return news;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followlist.find(followerId)==followlist.end())
        {
            set<int> s;
            s.insert(followeeId);
            followlist[followerId]=s;
        }
        else
        {
            followlist[followerId].insert(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        auto itr=followlist[followerId].find(followeeId);
        if(itr!=followlist[followerId].end())
        {
            followlist[followerId].erase(itr);
        }
    }
private:
    unordered_map<int,set<int>> followlist;
    vector<pair<int,int>> tweets_pool;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
