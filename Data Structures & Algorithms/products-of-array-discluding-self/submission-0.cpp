class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector <int> p(size),s(size);
        p[0] = 1;
        s[size-1] = 1;
        for(int i=1;i<size;i++){
            p[i]=nums[i-1]*p[i-1];
        }
        for(int i = size-2;i>=0;i--){
            s[i]=nums[i+1]*s[i+1];
        }
        vector <int> ans(size);
        for(int i=0;i<size;i++){
            ans[i] = s[i]*p[i];
        }
        return ans;


    }
};
