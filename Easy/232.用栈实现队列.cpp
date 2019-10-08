/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        mystack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        vector<int> numbers;
        while(!mystack.empty())
        {
            numbers.push_back(mystack.top());
            mystack.pop();
        }
        for(int i=numbers.size()-2;i>=0;i--)
        {
            mystack.push(numbers[i]);
        }
        return numbers[numbers.size()-1];
    }
    
    /** Get the front element. */
    int peek() {
        stack<int>  tempstack=mystack;
        int temp=0;
        while(!tempstack.empty())
        {
            temp=tempstack.top();
            tempstack.pop();
        }
        return temp;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return mystack.empty();
    }
private:
    stack<int> mystack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

