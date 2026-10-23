class Solution {
public:
    int minima(int i,vector<int>& dp, vector<int>& cost){
        if (dp[i] != 1001) return dp[i];
        dp[i] = min(minima(i-2,dp,cost)+ cost[i-2],minima(i-1,dp,cost)+cost[i-1]);
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> dp(size,1001);
        if(size==2) return min(cost[0],cost[1]);
        dp[0] = 0;
        dp[1] = 0;
        minima(size-1,dp,cost);
        return(min(dp[size-1]+cost[size-1],dp[size-2]+cost[size-2]));
    }
};
