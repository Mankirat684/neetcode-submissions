class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        vector<int> result(temperatures.size(), 0);
        for(int i=0;i<temperatures.size();i++){
            while(!(st.empty()) && st.top().first<temperatures[i]){
                
                pair <int,int> p = st.top();
                st.pop();
                // st.push({temperatures[i],i});
                int r = i-p.second;
                result[p.second] = r; 
            }
            st.push({temperatures[i],i});

        }
        return result;
    }
};
