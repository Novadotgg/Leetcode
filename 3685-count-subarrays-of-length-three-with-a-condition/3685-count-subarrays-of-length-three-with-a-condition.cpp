class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        
        for (int i = 0; i <= nums.size() - 3; i++) {
            if (nums[i] + nums[i+2] == nums[i+1] / 2.0) {
                count++;
            }
        }
        
        return count;
    }
};
