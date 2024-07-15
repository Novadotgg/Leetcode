/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int,bool>isChild;
        unordered_map<int,TreeNode*>mp;
        for(auto x:desc){
            if(mp.find(x[0]) == mp.end()){
                TreeNode*node = new TreeNode(x[0]);
                mp[x[0]] = node;
            }
            
            if(mp.find(x[1]) == mp.end()){
                TreeNode *child = new TreeNode(x[1]);
                mp[x[1]] = child;
            }
            
            if(x[2] == 1) mp[x[0]]->left = mp[x[1]];
            if(x[2] == 0) mp[x[0]]->right = mp[x[1]];
            isChild[x[1]] = true;
        }
        
        TreeNode*ans = NULL;
        for(auto x:desc){
            if(isChild[x[0]] == false){
                ans = mp[x[0]];
                return ans;
            }
        }
        
        return ans;
    }
};