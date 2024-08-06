class Solution {
public:
    int balancedStringSplit(string s) {
        // int i=0,j=s.size()-1;
        // int count=0;
        // while(i<j){
        //     if(s[i]!=s[j]){
        //         count+=1;
        //         i++;
        //         j--;
        //     }
        //     else{
        //         i++;
        //         j--;
        //         count+=1;
        //     }
        // }
        // return count;
        int i = 0, j = s.size() - 1;
        int count=0;
        int L=0;
        int R=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L') L++;
            else R++;
            if(L==R)count++;
        }
        return count;
    }
};