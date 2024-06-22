class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=0,count=0, i=0,j=0;
        while(j<nums.size()){
            if(nums[j]%2!=0){
                k--;
                count=0;
            }
            while(k==0){
                if(nums[i] % 2 != 0){
                    k++;
                }
                count++;
                i++;
            }
            ans+=count;
            j++;
        }
        return ans;
    }
};