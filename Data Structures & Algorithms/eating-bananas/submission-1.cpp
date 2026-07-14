class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int size = piles.size();
        int l=1,r=*(max_element(piles.begin(),piles.end()));
        if(size>h) return -1;
        int mid = r - (r-l)/2;
        while(l<r){
            mid = l + (r-l)/2;
            int tempTime = 0;
            for(int i=0;i<size;i++){
                tempTime += (piles[i] + mid - 1) / mid; 
            }
            if(tempTime>h){
                l = mid+1;
            }else{
                r = mid;
            }
              
        }
        return l;
    }
};
