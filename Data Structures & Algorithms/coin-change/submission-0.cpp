class Solution {
   public:
    int solve(int i, vector<int>& coins, vector<int>& dp) {
        if (i == 0) return 0;

        if (i < 0) return INT_MAX;

        if (dp[i] != -1) return dp[i];
        int ans = INT_MAX;

        for (int c : coins) {
            int temp = solve(i - c, coins, dp);
            if (temp != INT_MAX) ans = min(ans, temp + 1);
        }
        return dp[i] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        int res = solve(amount, coins, dp);
        
        return res == INT_MAX? -1 : res;
    }
};
