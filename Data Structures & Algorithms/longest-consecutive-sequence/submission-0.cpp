class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         unordered_map<int,int> hash;
        if(nums.size()==0)return 0;
        int longest = 1;
        for(int num:nums){
            hash[num]++;
        }
        for(auto num:hash){
            if(hash.count(num.first-1))continue;
            int count = 1;
            int j=1;
            while(hash.count(num.first+j)){
                count++;
                longest = max(count,longest);
                j++;

            }
        }
        return longest;
    }
};
