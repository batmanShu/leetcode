class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        minval=INT_MAX;
    }
    
    void push(int x) {
        s.push(x);
        mins.push_back(x);
        if(x<minval) minval=x;
    }
    
    void pop() {
        if(s.top()==minval)
        {
            sort(mins.begin(),mins.end());
            mins.erase(mins.begin());
            if(mins.size()==0) minval=INT_MAX;
            else minval=mins[0];
            s.pop();
        }
        else
        {
            for(auto itr=mins.begin();itr!=mins.end();itr++)
            {
                if(*itr==s.top())
                {
                    mins.erase(itr);
                    break;
                }
            }
            s.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return minval;
    }
private:
    int minval;
    stack<int> s;
    vector<int> mins;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
