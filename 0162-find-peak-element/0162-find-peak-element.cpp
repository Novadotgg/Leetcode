class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // int ans;
        // for(int i=1;i<nums.size();i++){
        //     if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
        //         return i;
        //     }
        // }
        // return 0;
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            int mid=i+(j-i)/2;
            if(nums[mid]>nums[mid+1]){
                j=mid;
            }
            else{
                i=mid+1;
            }
        }
        return i;
    }
};