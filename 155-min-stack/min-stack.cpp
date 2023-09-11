class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if (min_s.empty() == false) {
            int entry = min(min_s.top(), val);
            min_s.push(entry);
        }
       else {
           min_s.push(val);
       }
        
    }
    
    void pop() {
        s.pop();
        min_s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top();
    }

    private:
        stack<int> s;
        stack<int> min_s;


};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */