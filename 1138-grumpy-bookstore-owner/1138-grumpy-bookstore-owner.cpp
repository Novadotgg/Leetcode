//customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
//1+1+1+1+7+5
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int initial=0;
        int current=0;
        int maxi=0;
        for(int i=0;i<customers.size();i++){
            if(grumpy[i]==0){
                initial+=customers[i];
            }
            else if(i<minutes){
                current+=customers[i];
            }
        }
        maxi=current;
        for(int i=minutes;i<customers.size();i++){
            current+=customers[i]*grumpy[i];
            current-=customers[i-minutes]*grumpy[i-minutes];
            maxi=max(current,maxi);
        }
        return (maxi+initial);
    }
};