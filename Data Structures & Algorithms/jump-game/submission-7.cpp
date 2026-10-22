class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int farthest = 0;
        if(size<2) return true;
        
        for (int i = 0; i < size; i++) {
            if(i>farthest) return false;
            farthest = max(farthest,nums[i]+i);
            if(i+nums[i]>= size-1) return true;

        }
        return true;
        
    }
};
