class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--){
        int num = nums[0];
        int index = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < num){
                num = nums[i];
                index = i;
            }
        }
        nums[index] = nums[index]*multiplier;
        }
        return nums;
    }
};