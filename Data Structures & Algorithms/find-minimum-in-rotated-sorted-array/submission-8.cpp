class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0;
        int size = nums.size();
        int high = size - 1;
        int mid;
        
        while(high>=low){
        if (nums[low]<=nums[high]) return nums[low];
            mid = low+(high-low)/2;
            // if(nums[mid % size]<nums[(mid+1)%size]&&nums[mid % size]<nums[(mid - 1 + size)%size]){
            //     return nums[mid];
            // }else if(nums[mid%size]>nums[high]){
            if(nums[mid%size]>nums[high]){
                low = mid+1;
            }else {
                high = mid;
            }
        }
        return -1111;
    }
};
