class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(2);
        
        dp[0]=cost[0];
        dp[1]=cost[1];
        if(n<2) return min(cost[0],cost[1]);
        

        for(int i=2;i<n;i++){
            int curr=cost[i]+min(dp[0],dp[1]);
            dp[0]=dp[1];
            dp[1]=curr;
        }
        return min(dp[0],dp[1]);
    }
};