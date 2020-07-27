struct Node{
    int val;
    Node* prev;
    Node* next;
    Node(int _val):val(_val),prev(nullptr),next(nullptr){}
};

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        cnt=0;
        maxsize=k;
        head=new Node(-1);
        tail=new Node(-1);
        head->next=tail;
        tail->prev=head;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull())
            return false;
        Node* node=new Node(value);
        node->next=head->next;
        node->prev=head;
        head->next=node;
        node->next->prev=node;
        cnt++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull())
            return false;
        Node* node=new Node(value);
        node->next=tail;
        node->prev=tail->prev;
        tail->prev=node;
        node->prev->next=node;
        cnt++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(cnt==0)
            return false;
        head->next->next->prev=head;
        head->next=head->next->next;
        cnt--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(cnt==0)
            return false;
        tail->prev->prev->next=tail;
        tail->prev=tail->prev->prev;
        cnt--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(cnt==0)
            return -1;
        return head->next->val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(cnt==0)
            return -1;
        return tail->prev->val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if(cnt==0)
            return true;
        return false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if(cnt==maxsize)
            return true;
        return false;
    }
private:
    int cnt;
    int maxsize;
    Node* head;
    Node* tail;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
