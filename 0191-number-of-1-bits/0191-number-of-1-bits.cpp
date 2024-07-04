class Solution {
public:
    int hammingWeight(int n) {
        int count =0;
        if(n==0) return 0;
        string binary= " ";
        while(n>0){
            binary=to_string(n%2)+binary;
            n=n/2;
        }
        for(int i=0;i<binary.size();i++){
            if(binary[i]=='1'){
                count++;
            }
        }
        return count;
    }
};