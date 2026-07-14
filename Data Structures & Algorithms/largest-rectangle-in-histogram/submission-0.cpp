class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int left=0;
        int right=0;
        for(int i=0; i<heights.size(); i++){
            left = i ;
                int minHeight = heights[i];
            for(int j=i;j<heights.size();j++){
                right = j;
                int index = j-i+1;
                minHeight = min(minHeight , heights[j]);
                maxArea = max(minHeight*index , maxArea);
            }
        }
        return maxArea;
    }
};
