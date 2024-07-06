class Solution {
public:
    int passThePillow(int n, int time) {
        int ans=0;
        bool foreward=true;
        for(int i=0;i<time;i++){
            if(foreward){
                ans++;
                if(ans==n-1){
                    foreward=false;
                }
            }
            else{
                ans--;
                if(ans==0){
                    foreward=true;
                }
            }
        }
        return ans+1;
    }
};