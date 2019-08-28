/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        if (nums.size() == 1)
            return new TreeNode(nums[0]);
        return DFS(nums, 0, nums.size() - 1);
    }
    
    TreeNode* DFS(vector<int>& nums, int start, int end) {
        if(start > end)
            return NULL;
        int mid = (start + end + 1) / 2; //相同情况下，右节点为空，如例子
        // int mid = (start + end + 1) / 2; 相同情况下，做节点为空
        TreeNode *root = new TreeNode(nums[mid]);
        root -> left = DFS(nums, start, mid - 1);
        root -> right = DFS(nums, mid + 1, end);
        return root;
    }

};

