class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2, nums1);
         
        int leftSize = (m + n + 1) / 2;
        int leftx = INT_MIN, lefty = INT_MIN, rightx = INT_MIN, righty = INT_MIN;
        int partitionX,partitionY;
        int l = 0,h = m;
        
        while (l<=h) {

            partitionX = l+(h-l)/2;
            partitionY = leftSize - partitionX;
            leftx = partitionX == 0 ? INT_MIN : nums1[partitionX - 1];
            lefty = partitionY == 0 ? INT_MIN : nums2[partitionY - 1];
            rightx = partitionX == m ? INT_MAX : nums1[partitionX];
            righty = partitionY == n ? INT_MAX : nums2[partitionY];

            if(leftx <= righty && lefty <= rightx){
                if((m+n) % 2 != 0)return max(leftx,lefty);
                return static_cast<double>(
                    max(leftx,lefty) + min(rightx,righty)
                    )/2.0;
            }

            if (leftx > righty) {
                h = partitionX-1;
            } else{
                l = partitionX+1;
            }

        }
        return -1;
    }
};
