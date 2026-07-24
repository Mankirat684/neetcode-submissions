class Solution {
public:
    int solve(int i,vector<int>& nums,vector<int>& dp){
        
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i] = max(solve(i-1,nums,dp),nums[i]+solve(i-2,nums,dp));
    }
    int rob(vector<int>& nums) {
        int s =nums.size();
        if(s<=1) return nums[0];

        vector<int> dp_1(s-1,-1),dp_2(s-1,-1);
        if(s==2) return max(nums[0],nums[1]);
        dp_1[0] = nums[0];
        dp_1[1] = max(nums[0],nums[1]);
        dp_2[0] = nums[1];
        dp_2[1] = max(nums[1],nums[2]);
        int temp = nums[s-1];
        nums.pop_back();
        int num1 = solve(s-2,nums,dp_1);
        nums.push_back(temp);
        nums.erase(nums.begin());
        int num2 = solve(s-2,nums,dp_2);
        return max(num1,num2);
        
    }
};
