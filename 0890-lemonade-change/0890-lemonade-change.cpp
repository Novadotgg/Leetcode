class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count_5=0;
        int count_10=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                count_5++;
                continue;
            }
            if(bills[i]==10){
                count_10++;
            }

            if(bills[i]==10 && count_5>0){
                count_5--;
            }
            else if(bills[i]==20 && count_10>0 && count_5>0){
                count_5--;
                count_10--;
                cout<<"hello"<<endl;
            }
            else{
                if(bills[i]==20 && count_5>=3){
                    count_5-=3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};