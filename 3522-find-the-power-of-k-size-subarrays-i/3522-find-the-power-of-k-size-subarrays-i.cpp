class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        // int i=0;
        // int j=k-1;
        // for(int a=0;a<nums.size();a++){
        //     for(int num:nums)
        // }
        int n=nums.size();
        vector<int> ans(n-k+1,-1);
        int score=0;
        for(int i=0;i<n;i++){
            if(i && nums[i-1]+1==nums[i])score ++;
            else score=0;
            if(score >=k-1) ans[i-k+1]=nums[i];
        }
        return ans;
    }
};