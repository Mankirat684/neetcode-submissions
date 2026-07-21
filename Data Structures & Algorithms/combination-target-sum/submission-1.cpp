class Solution {
public:
    void dfs(int index,vector<int>& choices,int target,vector<vector<int>>& ans,vector<int>& current){
        if(target == 0){
            ans.push_back(current);
            return;
        }

        for(int i = index;i<choices.size();i++){
            if(target-choices[i]<0) continue;
            current.push_back(choices[i]);
            dfs(i,choices,target-choices[i],ans,current);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> current;
        vector<vector<int>> ans;
        dfs(0,nums,target,ans,current);
        return ans;
    }
};
