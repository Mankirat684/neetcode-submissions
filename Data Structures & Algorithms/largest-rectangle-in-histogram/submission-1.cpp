class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        vector <int> leftNse(heights.size()),rightNse(heights.size());
        stack<int> lst,rst;
        for(int i=0;i<heights.size(); i++){
            while(!lst.empty()&&heights[lst.top()]>=heights[i]){
                lst.pop();
            }
            leftNse[i] = lst.empty()?-1:lst.top();
            lst.push(i);
            
        }
        for(int i=heights.size()-1; i>=0; i--){
            while(!rst.empty()&&heights[rst.top()]>=heights[i]){
                rst.pop();
            }
            rightNse[i] = rst.empty()?heights.size():rst.top();
            rst.push(i);
            
        }

        for(int i=0; i<heights.size(); i++){

            int index = rightNse[i] - leftNse[i] - 1;
        maxArea = max(heights[i]*index,maxArea);    

    }
        return maxArea;
    }
};
