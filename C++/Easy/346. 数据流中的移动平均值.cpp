class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        maxsize=size;
        dq.clear();
        prev_avg=0;
    }
    
    double next(int val) {
        if(dq.size()<maxsize)
        {
            prev_avg=(prev_avg*dq.size()+val)/(dq.size()+1);
            dq.push_back(val);
            return prev_avg;
        }
        else
        {
            prev_avg=(prev_avg*dq.size()+val-dq.front())/(dq.size());
            dq.pop_front();
            dq.push_back(val);
            return prev_avg;
        }
    }
private:
    deque<int> dq;
    double prev_avg;
    int maxsize;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
