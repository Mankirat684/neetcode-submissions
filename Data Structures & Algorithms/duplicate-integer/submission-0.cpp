class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
     unordered_map<int,int> hash;
     for(int n:nums){
        hash[n]++;
        if(hash[n]>1)return true;
     }   
    return false;
    }
    
    
};