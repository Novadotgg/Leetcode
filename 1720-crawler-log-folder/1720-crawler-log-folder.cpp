class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count =0;
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="./"){
                continue;
            }
            else if(logs[i]=="../"){
                count --;
                if(count<0){
                    count=0;
                }
            }
            else{
                count ++;
            }
        }
        return count;
    }
};