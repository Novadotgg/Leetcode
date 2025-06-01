/*
limit=2
n=5 candies
children = 3

someone can get atmost 2 or "limit" candies

I need to make subarray sum = n 

take count = 0

1 -> 5
1 -> limit
if(n<limit) return "nhi hoga"

(2,_,_ )





*/

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        //Total children = 3
        long long res=0;
        for(int i=0;i<=min(limit,n);i++){
            if(n-i<=2*limit){
                res+=min(n-i,limit)- max(0,n-i-limit)+1;
            }
        }
        return res;
        
    }
};