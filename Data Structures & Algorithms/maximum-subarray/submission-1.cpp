class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        for(int i = 0; i<nums.size();i++){
            sum+=nums[i];
            if(nums[i]>sum){
                sum = nums[i];
                maxi = max(maxi,sum);
                continue;
            }
            maxi= max(sum,maxi);
        }
        return maxi;
    }
};
