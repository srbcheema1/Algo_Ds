# Definition for a binary tree node.
import collections

class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.left = left
        self.right = right
        self.val = val


# -> List[List[int]]:
class Solution:
    def levelOrder(self, root):
        self.l=collections.defaultdict(list)
        def dfs(r, lv):
            if not r:
                return 
            self.l[lv].append(r.val)
            dfs(r.left, lv+1)
            dfs(r.right, lv+1)
            return 
        dfs(root, 0)
        r =[]
        for key in sorted(self.l.keys(), reverse =False):
            r.append(self.l[key])
        return r


# intiate nodes of the Tree
t_root = TreeNode(100)
node_60 = TreeNode(60)
node_50 = TreeNode(50)
node_40 = TreeNode(40)
node_30 = TreeNode(30)
node_150 = TreeNode(150)
node_160 = TreeNode(160)
node_180 = TreeNode(180)
node_190 = TreeNode(190)
node_220 = TreeNode(220)

#Build Tree
t_root.left = node_50
t_root.right = node_180
node_50.left = node_40
node_40.left = node_30
node_50.right = node_60
node_180.left = node_150
node_180.right = node_190
node_150.right = node_160
node_190.right  = node_220

print(t_root.val)

sol = Solution()
result = sol.levelOrder(t_root)
print(result)
