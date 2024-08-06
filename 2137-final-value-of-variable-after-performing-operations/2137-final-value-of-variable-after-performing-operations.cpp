class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int p=0,n=0;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="++X"|| operations[i]=="X++"){
                p++;
            }
            else{
                n--;
            }
        }
        return p+n;
    }
};