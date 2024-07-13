// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         vector<int> ans;
//         int start=nums[0];
//         int end=nums.size()-1;
//         int mid=start+(start-end)/2;
//         while(start<end){
//             if(mid>target){
//                 end=mid-1;
//             }
//             if(mid<target){
//                 start=mid+1;
//             }
//             if(target==mid){
//                 ans.push_back(mid);
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);  
        int start = 0, end = nums.size() - 1;

        // Find the first occurrence of target
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                ans[0] = mid;
                end = mid - 1;  
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        start = 0;
        end = nums.size() - 1;

        // Find the last occurrence of target
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                ans[1] = mid;
                start = mid + 1;  
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }
};
