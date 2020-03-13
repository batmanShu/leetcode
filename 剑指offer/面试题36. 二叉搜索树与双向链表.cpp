/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        Node* leftnode=treeToDoublyListCore(root->left);
        Node* rightnode=treeToDoublyListCore(root->right);
        Node* head=leftnode;
        if(leftnode)
        {
            while(leftnode->right) leftnode=leftnode->right;
            leftnode->right=root;
            root->left=leftnode;
            root->right=rightnode;
            if(rightnode)
            {
                rightnode->left=root;
                while(rightnode->right) rightnode=rightnode->right;
                rightnode->right=head;
                head->left=rightnode;
            }
            else
            {
                root->right=head;
                head->left=root;
            }
        }
        else
        {
            head=root;
            root->right=rightnode;
            if(rightnode)
            {
                rightnode->left=root;
                while(rightnode->right) rightnode=rightnode->right;
                rightnode->right=head;
                head->left=rightnode;
            }
            else
            {
                root->left=root;
                root->right=root;
            }
        }
        return head;
    }
    //core中不把首尾连接起来
    Node* treeToDoublyListCore(Node* root){
        if(!root) return nullptr;
        Node* leftnode=treeToDoublyListCore(root->left);
        Node* rightnode=treeToDoublyListCore(root->right);
        Node* head=leftnode;
        if(leftnode)
        {
            while(leftnode->right) 
            {
                Node* prevnode=leftnode;
                leftnode=leftnode->right;
                leftnode->left=prevnode;
            }
            leftnode->right=root;
            root->left=leftnode;
            root->right=rightnode;
            if(rightnode)
            {
                rightnode->left=root;
            }
        }
        else
        {
            head=root;
            root->right=rightnode;
            if(rightnode)
            {
                rightnode->left=root;
            }
            root->left=nullptr;
        }
        return head;
    }
};
