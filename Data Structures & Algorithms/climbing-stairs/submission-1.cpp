class Solution {
public:
    int dP(int n, vector<int>& dp){
        if(dp[n]!=-1){
            return dp[n];
        }
        
        dp[n] = dP(n-1,dp)+dP(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        if(n<=1) return 1;
        vector<int> dp(n+1,-1);
        dp[0]=1; 
        dp[1]=1;
        return dP(n,dp);

        
    }
};
