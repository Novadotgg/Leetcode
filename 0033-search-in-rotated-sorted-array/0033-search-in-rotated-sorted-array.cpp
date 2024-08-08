// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         sort(nums.begin(), nums.end());
//         int left=0;
//         int ans;
//         int right=nums.size()-1;
//         int mid= right-(left+right)/2;
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
            
//             if (nums[mid] == target) {
//                 return mid;  
//             }
//             else if (nums[mid] >= nums[left]) {
//                 if (nums[left] <= target && target <= nums[mid]) {
//                     right = mid - 1;
//                 } else {
//                     left = mid + 1;
//                 }
//             } else {
//                 if (nums[mid] <= target && target <= nums[right]) {
//                     left = mid + 1;
//                 } else {
//                     right = mid - 1;
//                 }
//             }
//         }

//         return -1;         
//     }
// };
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] >= nums[left]) {
                if (nums[left] <= target && target <= nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;        
    }
};