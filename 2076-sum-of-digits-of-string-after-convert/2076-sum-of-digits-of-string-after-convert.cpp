class Solution {
public:
    int getLucky(string s, int k) {
        string nS="";
        for(char ch: s){
            nS+=to_string(ch - 'a' +1);
        }
        while(k>0){
            int digitsum=0;
            for(char digit :nS){
                digitsum += digit - '0';
            }
            nS=to_string(digitsum);
            k--;
        }
        return stoi(nS);
    }
};