#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // If the root is null, return -1 as there's no tree
        if (!root) return -1;

        vector<long long> res;  // Store level sums
        queue<TreeNode*> q;  // Queue to perform BFS level order traversal
        q.push(root);

        // Perform level order traversal using the queue
        while (!q.empty()) {
            int size = q.size();  // Number of nodes at the current level
            long long levelSum = 0;  // Sum of the current level

            // Traverse all nodes of the current level
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;  // Add node's value to level sum

                // Push the child nodes to the queue for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            res.push_back(levelSum);  // Store the sum of the current level
        }

        // Sort the results to find the kth largest
        sort(res.begin(), res.end(), greater<long long>());

        // Check if k is valid (if there are fewer than k levels, return -1)
        if (k > res.size()) return -1;

        return res[k - 1];  // Return the kth largest sum (1-based index)
    }
};
