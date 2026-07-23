class Solution {
public:
    int solve(int i,vector<int>& nums,vector<int>& dp){
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i] = max(solve(i-1,nums,dp),nums[i]+solve(i-2,nums,dp));
    }
    int rob(vector<int>& nums) {
        if(nums.size()<=1) return nums[0];

        vector<int> dp(nums.size(),-1);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        return solve(nums.size()-1,nums,dp); 
    }
};
