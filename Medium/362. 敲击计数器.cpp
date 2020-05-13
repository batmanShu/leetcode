class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {

    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        curtime=timestamp;
        pool.push_back(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        curtime=timestamp;
        while(!pool.empty()&&curtime-pool.front()>=300)
        {
            pool.pop_front();
        }
        return pool.size();
    }
private:
    int curtime=0;
    deque<int> pool;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
