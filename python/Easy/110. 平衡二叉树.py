# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        def getDepth(root: TreeNode) -> int:
            if root == None:
                return 0
            else:
                return max(getDepth(root.left),getDepth(root.right))+1
        if root == None:
            return True
        leftDepth = getDepth(root.left)
        rightDepth = getDepth(root.right)
        if abs(leftDepth-rightDepth) > 1:
            return False
        else:
            return self.isBalanced(root.left) and self.isBalanced(root.right)
