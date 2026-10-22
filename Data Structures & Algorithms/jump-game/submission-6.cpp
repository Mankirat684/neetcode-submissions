class Solution {
   public:
    bool canJump(vector<int>& nums) {
        vector<int> available;
        unordered_map<int, int> hash;
        int size = nums.size();
        if(size<2) return true;
        available.push_back(0);
        hash[0] = 1;
        for (int i = 0; i < available.size(); i++) {
            int curr = available[i];
            for (int j = 1; j <= nums[curr]; j++) {
                if (hash.count(curr + j) != 1) {
                    if((curr+j)>=size) break;
                    available.push_back(curr + j);
                    hash[curr+j] = 1;
                }
            }
        }
        if (hash.count(size-1)) return true;
        return false;
    }
};
