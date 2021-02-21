/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        mylist.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp=mylist.back();
        mylist.pop_back();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        return mylist.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return mylist.empty();
    }
private:
    list<int> mylist;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

