class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        int median=findMedian();
        if(num>median) minheap.push(num);
        else maxheap.push(num);
        if(minheap.size()>maxheap.size())
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
        else if(maxheap.size()-minheap.size()>1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }
    
    double findMedian() {
        if(maxheap.size()+minheap.size()==0) return double(INT_MIN);
        if((maxheap.size()+minheap.size())%2==0) return (maxheap.top()+minheap.top())/2.0;
        return maxheap.top();
    }
private:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
