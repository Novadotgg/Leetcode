class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long l=0;
        long r=0;
        for(int i:nums){
            r+=i;
        }
        int split=0;
        for(int i=0;i<nums.size()-1;i++){
            l+=nums[i];
            r-=nums[i];
            if(l>=r)split++;
        }
        return split;
    }
};