class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int prevMax;
        int left,right; 
        vector<int> ans;
        left = 0;
        right = k-1;
        while(right<nums.size()){
        int largest = -1000000;
            for(int i=left;i<=right;i++){
                largest = max(largest,nums[i]); 
            }
            ans.push_back(largest);
            left++;
            right++;
        }
        return ans;
    }
};
