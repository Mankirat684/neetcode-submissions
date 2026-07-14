class MinStack {
public:
    vector<int> st,mn;  
    MinStack() {
    }
    
    void push(int val) {
        st.push_back(val);
        if(mn.empty()) mn.push_back(val);
        else{
            mn.push_back(min(val,mn.back()));
        }
    }
    
    void pop() {
        st.pop_back();
        mn.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return mn.back();
    }
};
