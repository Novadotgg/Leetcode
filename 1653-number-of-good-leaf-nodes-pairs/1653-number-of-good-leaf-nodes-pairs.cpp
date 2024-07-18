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
private:
    vector<int> dfs(TreeNode* root, int distance, int &c){
        if(!root) return{0};
        if(!root->left && !root->right) return {1};
        vector<int> left=dfs(root->left,distance, c);
        vector<int> right=dfs(root->right, distance, c);
        for(int x:left){
            for(int y:right){
                if(x>0 && y>0){
                    if(x+y<=distance)c++;
                }
            }
        }
        vector<int> ans;
        for(int x:left){
            if(x>0 && x<distance){
                ans.push_back(x+1);
            }
        }
        for(int x:right){
            if(x>0 && x<distance){
                ans.push_back(x+1);
            }
        }
        return ans;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        int count=0;
        dfs(root,distance, count);
        return count;
    }
};