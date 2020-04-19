class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        pool.clear();
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        curtime=timestamp;
        if(pool.find(message)==pool.end())
        {
            pool[message]=timestamp;
            return true;
        }
        else
        {
            if(curtime-pool[message]<10) return false;
            else
            {
                pool[message]=curtime;
                return true;
            }
        }
    }
private:
    int curtime=0;
    unordered_map<string,int> pool;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
