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


/*

                4
        8               5
    0       1       Null    6

    Node 4: (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4
    Node 5: (5 + 6) / 2 = 11 / 2 = 5.
    Node 0: 0 / 1 = 0.
    Node 1: 1 / 1 = 1.
    Node 6: 6 / 1 = 6.

    Return the number of Nodes, where Nodes=average of the subtree values


*/


class Solution {
public:

    int count_nodes(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }

        return 1 + count_nodes(root->left) + count_nodes(root->right);
    }

    int sum_nodes(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }

        return root->val 
             + sum_nodes(root->left) 
             + sum_nodes(root->right);
    }

    int averageOfSubtree(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }

        int count = 0;

        // Process current node
        int node = count_nodes(root);
        int sum = sum_nodes(root);

        if (root->val == sum / node) {
            count++;
        }

        // Process left subtree
        count += averageOfSubtree(root->left);

        // Process right subtree
        count += averageOfSubtree(root->right);

        return count;
    }
};