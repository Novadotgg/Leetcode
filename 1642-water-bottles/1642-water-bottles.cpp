class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // int ans=0;
        // ans+=numBottles;
        // int temp=numBottles/numExchange;
        // ans=ans+temp+1;
        // return ans;
        int ans = 0;
        int emptyBottles = 0;
        
        while (numBottles > 0) {
            ans += numBottles; // Drink all the full bottles
            emptyBottles += numBottles; // Collect all the empty bottles
            numBottles = emptyBottles / numExchange; // Exchange empty bottles for full ones
            emptyBottles %= numExchange; // Remainder of empty bottles that cannot be exchanged
        }
        
        return ans;
    }
};