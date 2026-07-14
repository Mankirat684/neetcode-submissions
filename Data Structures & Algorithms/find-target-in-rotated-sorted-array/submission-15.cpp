class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0;
        int size = nums.size();
        int high = size - 1;
        int mid;
        
        while(high>low){
           // if (nums[low]<=nums[high]) return low;
            mid = low+(high-low)/2;
            if(nums[mid]>nums[high]){
                low = mid+1;
            }else {
                high = mid;
            }
        }
        return low;
    }
    int search(vector<int>& nums, int target) {        
        int minIndex = findMin(nums);
        int l=minIndex;
        int size = nums.size();
        int r = (minIndex + size - 1);
        while(r>=l){
            int mid = l + (r-l)/2; 
            if(nums[mid%size] == target ) return mid%size;
            if(nums[mid%size]<target){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return -1;
    }
};