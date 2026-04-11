class MinStack {
    stack<pair<int, int>> st;//reg, min
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int min_val =val;
        if(!st.empty() && val > st.top().second) {
            st.push({val, st.top().second});
        } else {
            st.push({val, val});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
        
    }
};
