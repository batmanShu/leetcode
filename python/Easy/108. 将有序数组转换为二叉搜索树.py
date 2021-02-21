# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        def make_tree(left_ind, right_ind) -> TreeNode:
            if left_ind > right_ind:
                return None
            mid_ind = (left_ind + right_ind) // 2
            root = TreeNode(nums[mid_ind])
            root.left = make_tree(left_ind, mid_ind-1)
            root.right = make_tree(mid_ind+1, right_ind)
            return root
        return make_tree(0, len(nums)-1)