class HashNode{
public:
    int _val;
    int _key;
    HashNode* next;
    HashNode(int k, int v){
        _key=k;
        _val=v;
        next=nullptr;
    }
    HashNode& operator=(const HashNode& node)
    {
        _key  = node._key;
        _val = node._val;
        next = node.next;
        return *this;
    }
};
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        table=new HashNode* [size];
        for(int i=0;i<size;i++)
        {
            table[i]=nullptr;
        }
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int ind=key%size;
        if(this->get(key)==-1)
        {
            HashNode* node=new HashNode(key,value);
            if(table[ind]==nullptr)
            {
                table[ind]=node;
            }
            else
            {
                node->next=table[ind];
                table[ind]=node;
            }
        }
        else
        {
            int ind=key%size;
            HashNode* node=table[ind];
            while(node)
            {
                if(key==node->_key) 
                {
                    node->_val=value;
                    return;
                }
                node=node->next;
            } 
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int ind=key%size;
        if(table[ind]==nullptr) return -1;
        HashNode* node=table[ind];
        while(node)
        {
            if(key==node->_key) return node->_val;
            node=node->next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int ind=key%size;
        if(table[ind]==nullptr) return;
        HashNode* node=table[ind];
        HashNode* prev=nullptr;
        while(node)
        {
            if(node->_key==key)
            {
                if(prev==nullptr) 
                {
                    table[ind]=node->next;
                    return;
                }
                prev->next=node->next;
                delete(node);
                return;
            }
            prev=node;
            node=node->next;
        }
    }
private:
    int size=5;
    HashNode **table;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
