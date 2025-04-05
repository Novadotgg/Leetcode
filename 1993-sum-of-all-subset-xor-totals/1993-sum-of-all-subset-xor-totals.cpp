class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum=0;
        for(int i:nums){
            sum|=i;
        }
        return sum<<(nums.size()-1);
    }
};