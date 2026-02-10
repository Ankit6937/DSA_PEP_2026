class MinStack {
public:
    stack<int> st;
    stack<int> minst;
    MinStack() {
        
    }
    
    void push(int val) {
        if(!st.empty()){
            st.push(val);
            if(val<minst.top()) minst.push(val);
            else minst.push(minst.top());
        }
        else{
            st.push(val);
            minst.push(val);
        }
        
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
            minst.pop();
        }
        
    }
    
    int top() {
        return st.top();

        
    }
    
    int getMin() {
        return minst.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */