class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int fleet = 1;
        vector<pair<int,int>> vec;
        stack<pair<int,int>> st;
        for(int i=0;i<speed.size();i++){
            vec.push_back({position[i],speed[i]});
        }
        sort(vec.begin(), vec.end(), greater<pair<int, int>>());
        st.push(vec[0]);
        for(int i=1;i<speed.size();i++){
            if(vec[i].second>st.top().second){
                float cd1 = static_cast<float>(st.top().first-vec[i].first)/(vec[i].second-st.top().second);
                float cd2 = static_cast<float>(target - st.top().first)/st.top().second;
                if(cd1>cd2){
                    st.pop();
                    st.push(vec[i]);
                    fleet++;
                }
            }else{
                st.pop();
                st.push(vec[i]);
                fleet++;
            }
        }
        return fleet;
    }
};
