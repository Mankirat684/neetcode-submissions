
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> available;
        unordered_map<int, int> hash;
        int size = nums.size();

        if (size < 2) return true;

        available.push_back(0);
        hash[0] = 1;

        for (int i = 0; i < available.size(); i++) {
            int curr = available[i];

            for (int j = 1; j <= nums[curr]; j++) {
                int next = curr + j;

                if (next >= size) break;

                if (hash.count(next) == 0) {
                    available.push_back(next);
                    hash[next] = 1;
                }
            }
        }

        return hash.count(size - 1) > 0;
    }
};
