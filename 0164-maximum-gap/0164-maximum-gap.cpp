// class Solution {
// public:
//     int maximumGap(vector<int>& nums) {
//         int maxi=0;
//         if(nums.size()==1){
//             return 0;
//         }
//         int ans;
//         for(int i=1;i<nums.size();i++){
//             ans=max(maxi,(nums[i+1]-nums[i]));
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }

        // Sort the array first
        sort(nums.begin(), nums.end());

        int maxGap = 0;
        for (int i = 1; i < nums.size(); i++) {
            maxGap = max(maxGap, nums[i] - nums[i-1]);
        }

        return maxGap;
    }
};
