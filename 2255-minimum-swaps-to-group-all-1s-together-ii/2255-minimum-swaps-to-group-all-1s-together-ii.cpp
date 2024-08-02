class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        for(int i:nums){
            c+=i;
        }
        if(c==0 || c==n)return 0;
        int c1=0;
        for(int i=0;i<c;i++){
            c1+=nums[i];
        }
        int maxc=c1;
        for(int i=0;i<n;i++){
            c1-=nums[i];
            c1+=nums[(i+c)%n];
            maxc=max(maxc,c1);
        }
        return c-maxc;
    }
};