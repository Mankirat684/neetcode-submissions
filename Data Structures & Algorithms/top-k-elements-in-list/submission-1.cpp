class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> hash;
        
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        vector<vector<int>> bucketsOfFreq(nums.size()+1);
        for(auto it:hash){
            bucketsOfFreq[it.second].push_back(it.first);
        }
        for(int i=bucketsOfFreq.size()-1;i>=0;i--){
            // if(ans.size()==k) return ans;
            if(!bucketsOfFreq[i].empty()){
            for(auto num:bucketsOfFreq[i]){
                ans.push_back(num);
                if(ans.size()==k) return ans;
            }
            }
        }
        return ans;
    }
};