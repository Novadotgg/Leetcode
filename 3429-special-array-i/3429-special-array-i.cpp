// class Solution {
// public:
//     bool isArraySpecial(vector<int>& nums) {
//         for(int i=0;i<nums.size()-1;i++){
// if(nums[i]%2==0 && nums[i+1]%2!=0 || nums[i]%2!=0 && nums[i+1]%2==0){
//     return true;
// }
//             }
//   return false;  }
// };
// class Solution {
// public:
//     bool isArraySpecial(vector<int>& nums) {
//         if (nums.size() == 1) {
//             return true;
//         }
//         for(int i = 0; i < nums.size() - 1; i++) {
// //             if(nums[i]){
// // return true;}
//             if((nums[i] % 2 == 0 && nums[i+1] % 2 != 0) || (nums[i] % 2 != 0 && nums[i+1] % 2 == 0)) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        // If the array has only one element, return true
        if (nums.size() == 1) {
            return true;
        }
        
        // Check every pair of adjacent elements
        for (int i = 0; i < nums.size() - 1; ++i) {
            if ((nums[i] % 2 == 0 && nums[i + 1] % 2 == 0) || (nums[i] % 2 != 0 && nums[i + 1] % 2 != 0)) {
                return false;
            }
        }
        
        return true;
    }
};
