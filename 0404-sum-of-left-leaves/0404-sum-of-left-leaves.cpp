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
    int sumOfLeftLeaves(TreeNode* root) {
        // if(!root) return 0;
        // int ans=0;
        // queue<TreeNode*>q;
        // q.push(root);
        // while(!q.empty()){
        //     TreeNode* temp=q.front();
        //     // ans+=temp->val;
        //     q.pop();
        //     if(temp->left){
        //         if(!temp->left->left && !temp->left->right){
        //             ans+=temp->left->val;
        //         }
        //         else{
        //             q.push(temp->left);
        //         }
        //     if(temp->right){
        //         q.push(temp->right);
        //     }
        //     }
        // }
        // return ans;
        if (!root) return 0;
        
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node->left) {
          
                if (!node->left->left && !node->left->right) {
                    sum += node->left->val;
                } else {
                    q.push(node->left);
                }
            }
            
            if (node->right) {
                q.push(node->right);
            }
        }
        
        return sum;
    }
};

