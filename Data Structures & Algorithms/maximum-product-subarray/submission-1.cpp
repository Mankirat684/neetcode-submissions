class Solution {
public:
int curr =INT_MIN;
    int solve_max(int i,vector<int>& nums,vector<int>& maxs,vector<int>& mins){
        if(maxs[i]!=-1117) return maxs[i];
        maxs[i] = max(nums[i],max(nums[i]*solve_max(i-1,nums,maxs,mins),solve_min(i-1,nums,maxs,mins)*nums[i]));
        curr = max(maxs[i],curr);
        return maxs[i];
    }
    int solve_min(int i,vector<int>& nums,vector<int>& maxs,vector<int>& mins){
        if(mins[i]!=-1117) return mins[i];
        return mins[i] = min(nums[i],min(solve_min(i-1,nums,maxs,mins)*nums[i],nums[i]*solve_max(i-1,nums,maxs,mins)));
    }
    int maxProduct(vector<int>& nums) {
        vector<int> mins(nums.size(),-1117),maxs(nums.size(),-1117);
        mins[0] = nums[0];
        maxs[0] = nums[0];
        solve_max(nums.size()-1 , nums , maxs , mins);
        return max(max(curr,mins[nums.size()-1]),nums[nums.size()-1]);
    }
};
