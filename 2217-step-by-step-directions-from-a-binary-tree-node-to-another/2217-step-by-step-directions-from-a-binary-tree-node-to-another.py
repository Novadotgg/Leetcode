# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        self.path1=""
        self.path2=""
        def traverse(node):
            q=deque([[node,""]])
            while q:
                for i in range (len(q)):
                    n,path = q.popleft()
                    if n.val == startValue:
                        self.path1 = path
                    if n.val == destValue:
                        self.path2 = path
                    if self.path1 and self.path2:
                        return
                    if n.left:
                        q.append([n.left,path+"L"])
                    if n.right:
                        q.append([n.right,path+"R"])
        
        traverse(root)
        def LCP(s1,s2):
            for i in range(min(len(s1),len(s2))):
                
                if s1[i]!=s2[i]:
                    return i
            return min(len(s1),len(s2))
        if len(self.path1)==0:
            return self.path2
        
        
        ind = LCP(self.path1,self.path2)
        
        return "U"*(len(self.path1)-ind)+self.path2[ind:]