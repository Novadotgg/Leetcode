class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        // int alice=0, bob=0;
        // // for(int i=0;i<nums.size();i++){
        // //     if(nums[i]%10 && !nums[i]/10 && nums[i]%100 && !nums[i]/100){
        // //         alice+=nums[i];
        // //     }
        // //     else{
        // //         bob+=nums[i];
        // //     }
        // // }
        // // return alice>bob;
        // int single=0, dbl=0;
        // for(int i:nums){
        //     if(i<10)single+=i;
        //     else{
        //         dbl+=i;
        //     }
        // }
        // int total=single+dbl;
        // int alicebobsingle= total -dbl;
        // int alicebobdouble=total -single;
        
        // // if(single>alicebobsingle){
        // //     alice=single;
        // //     bob=alicebobsingle;
        // // }
        // // else if(dbl>alicebobdouble){
        // //     alice=dbl;
        // //     bob=alicebobdouble;
        // // }
        // // else{
        // //     return false;
        // // }
        // // return alice>bob;
        // if (single > alicebobsingle || dbl> alicebobdouble) {
        //     return true;
        // }

        // return false;
        int n=nums.size();
        int ssum=0,dsum=0;
        for(int i=0;i<n;i++){
            if(nums[i]<10){
                ssum+=nums[i];
            }
            else{
                dsum+=nums[i];
            }
        }
        if(ssum==dsum){
            return false;
        }
        return true;
    }
};