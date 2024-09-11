class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res=start^goal;
        int ans=0;
        while(res>0){
            ans+=res&1;
            res>>=1;
        }
        return ans;
    }
};