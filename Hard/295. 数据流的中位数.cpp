class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(maxheap.empty())
            maxheap.push(num);
        else
        {
            if(num<=maxheap.top())
            {
                maxheap.push(num);
                if(maxheap.size()>minheap.size()+1)
                {
                    minheap.push(maxheap.top());
                    maxheap.pop();
                }
            }
            else
            {
                minheap.push(num);
                if(maxheap.size()<minheap.size())
                {
                    maxheap.push(minheap.top());
                    minheap.pop();
                }
            }   
            
        }
    }
    
    double findMedian() {
        if(maxheap.size()>minheap.size())
            return maxheap.top();
        else
        {
            double res;
            double d1=maxheap.top();
            double d2=minheap.top();
            res=(d1+d2)/2;
            return res;
        }
    }
private:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<>> minheap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
