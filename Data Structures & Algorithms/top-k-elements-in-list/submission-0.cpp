class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for(int i=0;i<k;i++){
            int maxFreq = 0;
            int maxNum;
            for(auto n:hash){
                if(n.second>maxFreq){
                    maxFreq = n.second;
                    maxNum = n.first;
                }
            }
            auto it = hash.find(maxNum);
            hash.erase(it);
            ans.push_back(maxNum);
        }
        return ans;
    }
};
