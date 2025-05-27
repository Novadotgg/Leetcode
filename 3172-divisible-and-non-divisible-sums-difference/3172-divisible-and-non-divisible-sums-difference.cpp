class Solution {
public:
    int differenceOfSums(int n, int m) {
        long long sum=0;
        long long sum1=0;
        for(int i=1;i<=n;i++){
            if(i%m!=0)sum+=i;
            if(i%m==0)sum1+=i;
        }
        return (sum-sum1);
    }
};