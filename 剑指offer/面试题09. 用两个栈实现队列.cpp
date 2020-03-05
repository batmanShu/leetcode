class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s1.empty()) return -1;
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ret=s2.top();
        s2.pop();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ret;
    }
private:
    stack<int> s1;//插入时用的栈
    stack<int> s2;//删除时用的栈
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
