class MedianFinder {
   public:
    priority_queue<int> l_1;
    priority_queue<int, vector<int>, greater<int>> l_2;
    double prevMedian;
    int l, m;

    MedianFinder() {
        l = 0;
        m = 0;
        prevMedian = INT_MIN;
    }

    void addNum(int num) {
        if(l==0 && m == 0){
            l_1.push(num);
            l++;
            prevMedian = num;
            return;
        }
        findMedian();
        if (l > m) {
            if(num<prevMedian){
                int temp = l_1.top();
                l_1.pop();
                l_2.push(temp);
                l_1.push(num);
                
                m++;
            } else{
                l_2.push(num);
                m++;
            }
        } else if (l<m){
            if(num>prevMedian){
                int temp = l_2.top();
                l_2.pop();
                l_1.push(temp);
                l_2.push(num);
                l++;
                
            } else{
                l_1.push(num);
                l++;
            }
        }else {
            if(num<prevMedian){
                l_1.push(num);
                l++;
            } else {
                l_2.push(num);
                m++;
            }
        }
        
    }

    double findMedian() {
        if (l != m)  {
            if (l > m)
                prevMedian = l_1.top();
            else
                prevMedian = l_2.top();
            return prevMedian;
        }
        prevMedian = static_cast<double>(l_1.top() + l_2.top()) / 2;
        return prevMedian;
    }
};
