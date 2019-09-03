/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    vector<int> elements;
    vector<int> mins;
    
    void push(int x) {
        if(mins.size()==0)
        {
            mins.push_back(x);
        }
        else if(x<=mins[mins.size()-1])
        {
            mins.push_back(x);
        } 
        elements.push_back(x);
    }
    
    void pop() {
        if(elements[elements.size()-1]==mins[mins.size()-1])
        {
            mins.pop_back();
        }
        elements.pop_back();
    }
    
    int top() {
        return (elements[elements.size()-1]);
    }
    
    int getMin() {
        return mins[mins.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

