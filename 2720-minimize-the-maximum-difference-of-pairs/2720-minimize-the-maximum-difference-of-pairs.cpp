// class Solution {
// public:
//     bool canFormPairs(vector<int>& nums, int maxDiff, int p) {
//         int count = 0;
//         int i = 1;

//         while (i < nums.size()) {
//             if (nums[i] - nums[i - 1] <= maxDiff) {
//                 count++;
//                 i += 2; // skip the next to make sure pairs don't overlap
//             } else {
//                 i++;
//             }
//         }

//         return count >= p;
//     }

//     int minimizeMax(vector<int>& nums, int p) {
//         sort(nums.begin(), nums.end());

//         int left = 0;
//         int right = nums.back() - nums.front();  // max possible diff
//         int result = right;

//         while (left <= right) {
//             int mid = left + (right - left) / 2;

//             if (canFormPairs(nums, mid, p)) {
//                 result = mid;
//                 right = mid - 1;
//             } else {
//                 left = mid + 1;
//             }
//         }

//         return result;
//     }
// };

// one more version

class Solution {
public:
    // Your greedy logic for a fixed "maximum difference"
    bool canForm(vector<int>& nums, int maxDiff, int p) {
        int count = 0;
        for (int i = 1; i < nums.size(); ) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                count++;
                i += 2; // skip next to avoid overlap
            } else {
                i++;
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums.back() - nums.front();
        int ans = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (canForm(nums, mid, p)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
