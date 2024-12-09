// class Solution {
// public:
//     vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
// //         vector<bool> results;

// //         for (const auto& query : queries) {
// //             int from = query[0];
// //             int to = query[1];
// //             bool isSpecial = true;

// //             for (int i = from; i < to; ++i) {
// //                 if ((nums[i] % 2 == 0 && nums[i + 1] % 2 == 0) || 
// //                     (nums[i] % 2 != 0 && nums[i + 1] % 2 != 0)) {
// //                     isSpecial = false;
// //                     break;
// //                 }
// //             }

// //             results.push_back(isSpecial);
// //         }

// //         return results;
//         int n = nums.size();
//         vector<bool> parityChange(n - 1, false);

//         // Preprocess the array to find parity changes between adjacent elements
//         for (int i = 0; i < n - 1; ++i) {
//             if ((nums[i] % 2 == 0 && nums[i + 1] % 2 != 0) ||
//                 (nums[i] % 2 != 0 && nums[i + 1] % 2 == 0)) {
//                 parityChange[i] = true;
//             }
//         }

//         vector<bool> results;
        
//         // Process each query using the preprocessed information
//         for (const auto& query : queries) {
//             int from = query[0];
//             int to = query[1];
//             bool isSpecial = true;

//             for (int i = from; i < to; ++i) {
//                 if (!parityChange[i]) {
//                     isSpecial = false;
//                     break;
//                 }
//             }

//             results.push_back(isSpecial);
//         }

//         return results;
//     }
// };
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n, 0); // Initialize prefix array with size n
        
        // Calculate the prefix array
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1];
            if ((nums[i - 1] % 2 == 0 && nums[i] % 2 == 0) || (nums[i - 1] % 2 != 0 && nums[i] % 2 != 0)) {
                prefix[i]++;
            }
        }

        vector<bool> ans; // Result vector
        
        // Process the queries
        for (auto& q : queries) {
            int left = q[0], right = q[1];
            int specialCount = prefix[right] - (left > 0 ? prefix[left] : 0);
            ans.push_back(specialCount == 0);
        }

        return ans; // Return the result
    }
};