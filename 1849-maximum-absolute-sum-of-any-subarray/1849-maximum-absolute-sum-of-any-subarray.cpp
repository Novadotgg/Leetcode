class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
       int mn=0;
       int mx=0;
       int ps=0;
       for(int i=0;i<nums.size();i++){
        ps+=nums[i];
        mn=min(mn,ps);
        mx=max(mx,ps);
       } 
       return mx-mn;
    }
};